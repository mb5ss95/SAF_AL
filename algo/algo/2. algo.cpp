#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[500][500] = { 0 };
int used[500][500] = { 0 };
int row, col;
int sum = 0;
int cnt = 0;
int ans = 0;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };


void run(int y, int x) {

	if (cnt == 4) {
		if (sum > ans) ans = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= row || nx >= col) continue;
		if (used[ny][nx] == 1) continue;
	}
}

void tshape(int y, int x) {

}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> row >> col;
	vector<vector<int>> map(row, vector<int>(col, 0));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			// 갔던 곳은 가지 않는다
			used[i][j] = 1;
			// 합처리
			sum = sum + map[i][j];

			// 몇개의 블록을 봤는가?
			cnt++;

			run(i, j);

			used[i][j] = 0;

			sum = sum - map[i][j];

			cnt--;

			// T자 처리
			tshape(i, j);
		}
	}

}