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
// dp, top-bottom ����
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
int R, C;

int max(int a, int b) {
	return a > b ? a : b;
}

vector<pair<int, int>> path;

void dfs(int row, int col) {

	if (row == R) return; // �� ���� �ٱ��� ���� �� ���� ���� ������
	

	int dr[] = { 1, 1, 1 };
	int dc[] = { -1, 0, 1 };
	for (int i = 0; i < 3; i++) {
		int ny = row + dr[i];
		int nx = col + dc[i];
		/*
		1. ��λ� ���� ���� �ٽ� ���°�? <- ���� �ݺ��� �Ǵ°�? pass
		2. ���� ������ ����� ��ǥ�� ���°�?
		
		*/
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if (MAP[ny][nx] == 0) continue;
		path.push_back({ ny, nx });
		dfs(ny, nx);
		path.pop_back();
	}
}

int main()
{

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> MAP[i][j];
			DP[i][j] = -2134567890;
			//-2147483648
		}
	}
	path.push_back({ 1, 1 });
	dfs(1, 1);
	
	return 0;
}