#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct node {
	int y, x;
};

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector<vector<node>> v(4, vector<node>(3));
	char arr[4][3];
	int sy, sx;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			v[i][j] = { i, j };
			if (arr[i][j] == 'A') {
				sy = i;
				sx = j;
			}
		}
	}

	queue<node> q;
	q.push({ sy, sx });

	int dy[] = { -1,-1,-1, 0, 0, 1, 1, 1 };
	int dx[] = { -1, 0, 1, 1, 1, 0,-1,-1 };
	int cnt = 0;
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 3) continue;
			if (arr[ny][nx] == '0') continue;
			if (arr[ny][nx] == 'B') {
				cout << cnt;
				return 0;
			}
			q.push({ ny, nx });
			arr[ny][nx] = '0';
		}
	}
	
};
