#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	int MAP[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	    {0, 2, 0, 0, 0, 0, 0, 0, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	    {0, 0, 0, 0, 0, 0, 0, 100, 0, 0},
	    {0, 0, 0, 0, 0, 10, 0, 0, 0, 0},
	    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
	    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	    {1, 0, 0, 20, 0, 0, 0, 1, 0, 0},
	    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	int row, col;

	cin >> row >> col;

	MAP[row+0][col+0]; // 0��° �ڱ��ڽ�
	MAP[row+0][col-1]; // 1��° ����
	MAP[row+0][col+1]; // 2��° ������
	MAP[row-1][col+0]; // 3��° ��
	MAP[row+1][col+0]; // 4��° �Ʒ�

	int dr[] = { 0,0,0,-1,1 };
	int dc[] = { 0,-1,1,0,0 };

	for (int i = 0; i < 5; i++) {
		// d�� ������� ���� ��ǥ ���
		int nr = row + dr[i]; // row�� ���� �迭
		int nc = col + dc[i]; // col�� ���� �迭
		
		// ������ ����� ����
		if (nr < 0 || nc < 0) continue;
		if (nr > 9 || nc > 9) continue;

		//
		if (MAP[nr][nc] != 0) {
			for (int i = 0; i < MAP[nr][nc]; i++) cout << "BOOm!!";
		}
	}
	return 0;
}