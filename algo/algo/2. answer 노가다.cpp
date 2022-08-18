#include <iostream>
#include <queue>
using namespace std;

int n, m;
int MAP[500][500];
int ans = -2134567890;
int sum = 0;

// T ����迭
// 0 : ��
// 1 : �� 
// 2 : ��
// 3 : ��
int tydir[4][4] = {
	{0, 0, -1, 0},
	{0, 1, 1, 2},
	{0, -1, 0, 1},
	{0, 0, 0, 1}
};
int txdir[4][4] = {
	{0, 1, 1, 2},
	{0, 0, 1, 0},
	{0, 1, 1, 1},
	{0, 1, 2, 1}
};

// �� �� ����迭 
int lydir[2][4] = {
	{0, 0, 0, 0},
	{0, 1, 2, 3}
};
int lxdir[2][4] = {
	{0, 1, 2, 3},
	{0, 0, 0, 0}
};

// �� ����迭 
int sydir[] = { 0, 0, 1, 1 };
int sxdir[] = { 0, 1, 0, 1 };

// L ����迭 
int Lydir[4][4] = {
	{0, 1, 2, 2},
	{0, 0, 0, -1},
	{0, 0, 1, 2},
	{0, 1, 0, 0}
};
int Lxdir[4][4] = {
	{0, 0, 0, 1},
	{0, 1, 2, 2},
	{0, 1, 1, 1},
	{0, 0, 1, 2}
};

// �� L ����迭 
int rLydir[4][4] = {
	{0, 1, 2, 2},
	{0, 0, 0, 1},
	{0, 0, 1, 2},
	{0, 1, 1, 1}
};
int rLxdir[4][4] = {
	{0, 0, 0, -1},
	{0, 1, 2, 2},
	{0, 1, 0, 0},
	{0, 0, 1, 2}
};

// �� ����迭
int zydir[2][4] = {
	{0, 1, 1, 2},
	{0, 0, -1, -1}
};
int zxdir[2][4] = {
	{0, 0, 1, 1},
	{0, 1, 1, 2}
};

// ��  ������迭 
int rzydir[2][4] = {
	{0, 1, 1, 2},
	{0, 0, 1, 1}
};
int rzxdir[2][4] = {
	{0, 0, -1, -1},
	{0, 1, 1, 2}
};

void tshape(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int ny = y + tydir[i][j];
			int nx = x + txdir[i][j];
			// ����ٸ� T�ڸ������� ����!
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				break;
			}
			sum += MAP[ny][nx];
		}
		if (sum > ans)
			ans = sum;
	}
}

void lineshape(int y, int x) {
	for (int i = 0; i < 2; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int ny = y + lydir[i][j];
			int nx = x + lxdir[i][j];
			// ����ٸ� |�ڸ������� ����!
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				break;
			}
			sum += MAP[ny][nx];
		}
		if (sum > ans)
			ans = sum;
	}
}

void squareshape(int y, int x) {
	int sum = 0;
	for (int j = 0; j < 4; j++) {
		int ny = y + sydir[j];
		int nx = x + sxdir[j];
		// ����ٸ� ���ڸ������� ����!
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
			break;
		}
		sum += MAP[ny][nx];
	}
	if (sum > ans)
		ans = sum;
}

void Lshape(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int ny = y + Lydir[i][j];
			int nx = x + Lxdir[i][j];
			// ����ٸ� L�ڸ������� ����!
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				break;
			}
			sum += MAP[ny][nx];
		}
		if (sum > ans)
			ans = sum;
	}
}

void reverseLshape(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int ny = y + rLydir[i][j];
			int nx = x + rLxdir[i][j];
			// ����ٸ� ��L�ڸ������� ����!
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				break;
			}
			sum += MAP[ny][nx];
		}
		if (sum > ans)
			ans = sum;
	}
}

void  zshape(int y, int x) {
	for (int i = 0; i < 2; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int ny = y + zydir[i][j];
			int nx = x + zxdir[i][j];
			// ����ٸ� ���ڸ������� ����!
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				break;
			}
			sum += MAP[ny][nx];
		}
		if (sum > ans)
			ans = sum;
	}
}

void  reversezshape(int y, int x) {
	for (int i = 0; i < 2; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int ny = y + rzydir[i][j];
			int nx = x + rzxdir[i][j];
			// ����ٸ� �����ڸ������� ����!
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				break;
			}
			sum += MAP[ny][nx];
		}
		if (sum > ans)
			ans = sum;
	}
}

int main() {

	// input 
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> MAP[i][j];

	// dfs 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// T ��� üũ
			tshape(i, j);
			// | ��� üũ
			lineshape(i, j);
			// �� ��� üũ
			squareshape(i, j);
			// L ��� üũ
			Lshape(i, j);
			// �� L ��� üũ 
			reverseLshape(i, j);
			// �� ��� üũ
			zshape(i, j);
			// �� �� ��� üũ
			reversezshape(i, j);
		}
	}
	cout << ans;
}