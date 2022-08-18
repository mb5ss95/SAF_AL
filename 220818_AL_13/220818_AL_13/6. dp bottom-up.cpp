#include <iostream>
#include <vector>

using namespace std;

/*
1. ��(��� ���)�� �ٲ���ִ� ���� ���� ����
-> �������� ��� ��ġ�� �����ߴ°�?
2. ���ο��� : 2���� (row, col)
-> �迭 ���� dp[row][col] = �ش� ��ǥ���� ���� ���� �ִ�����
3. now��� ��Ȳ�� ������, �ش� ��Ȳ�� �߻��� �� �ִ� ����
4. �ش� ��Ȳ�� ���� ���� Ȱ���Ͽ� ��� �������
*/
// dp, bottom-up ����
/*
7 3 <- row col
1 0 0 <- MAP������(0�� ��, �� �� ����)
1 2 2
0 3 0
3 -10 -5
15 -10 50
15 -10 10
0 6 4
*/
int MAP[10][10] = { 0, };
int DP[10][10]; // DP[row][col] : row,col'����'���� ���� �ִ� ����

int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	int R, C;
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> MAP[i][j];
			DP[i][j] = -2134567890;
			//-2147483648
		}
	}

	// �ʱⰪ : ����ߴ� ��ǥ����?(���� ���� �� ���� ��) => 0�� �ʱⰪ���� ���� -> ����ؼ� 0������ �ƴϸ� ����Ѱ� �ƴ���
	//     ���� ���� DP���� ���� ��, ���� ���� �� ���� ���� ���� ������ ���� ������� ���� ���(�� �� ����غ�)
	//                                 ���� ���� �� �ִ� �ٸ� ���� ���� ������ ������� ������, �ٽ� ����� �ʿ� ���� �׳� ������ ���� ����

	for (int row = 1; row <= R; row++)
	{
		for (int col = 1; col <= C && col <= row; col++)
		{
			if (MAP[row][col] == 0) // ���� �ִ� ��ǥ
				continue;
			if (row == 1) { // �� �� ��ǥ�� '����'��ǥ�� �����Ƿ� ���� �� ����
				DP[row][col] = MAP[row][col];
				continue;
			}
			// DP[row][col]; // <- row,col���� �� �� �ִ� ��� : 3����(3���� ���⿡��)
			int maxPrevValue = -2134567890; // row,col�� �� �� �ִ� ����鿡�� ���� �� �ִ� '�ִ� ����'
			int dr[] = { -1,-1,-1 };
			int dc[] = { -1, 0, 1 };
			for (int i = 0; i < 3; i++)
			{
				int pr = row + dr[i];
				int pc = col + dc[i];
				if (pr <= 0 || pc <= 0 || pr > R || pc > C) continue; // ���� ������ ����� ����
				if (DP[pr][pc] == -2134567890) // ������� ���� ��ǥ�� => �� �� ���⿡ ���õ� ��ǥ => now�� �� �� ���� ���
					continue;
				// pr,pc : row,col���� �� �� �ִ� '����'��ǥ
				maxPrevValue = max(maxPrevValue, DP[pr][pc]);  // << ----Ư�� data�� �����ͼ� ��� : pr,pc���� ���µ� '�� ��'�̿��°�?
			}
			if (maxPrevValue == -2134567890) continue; // now�� �� �� �ִ� '����'��ǥ�� �����ٸ� ����
			int maxNowValue = maxPrevValue + MAP[row][col]; // row,col ���������� �ִ� ���� + row,col���� = row,col������ �ִ� ����
			DP[row][col] = maxNowValue;
		}
	}

	int ans = -2134567890;
	for (int col = 1; col <= C; col++)
		ans = max(ans, DP[R][col]);
	cout << ans;



	return 0;
}