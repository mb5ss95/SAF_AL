#include <iostream>
#include <queue>
#include <Windows.h>

using namespace std;

char map[10][10];

void action() {
	system("cls");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	Sleep(1000);
}

struct node {
	int y, x;
	int level;
};

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);

	int dy[] = {0, -1, 0, 1,  0};
	int dx[] = {0,  0, 1, 0, -1};
	int w, h;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		cin >> map[i];

	}

	int y, x;
	int cnt = 0;
	cin >> x >> y;

	queue<node> q;
	q.push({ y-1, x-1, 3 });

	int sum = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '1') sum++;
		}
	}
	int last = 3;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		action();

		for (int i = 0; i < 5; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (map[ny][nx] - '0' < 1) continue;
			
			q.push({ ny, nx, now.level + 1 });
			cnt++;
			map[ny][nx] = '0';
			if (h != 1 && w != 1) last = now.level + 1;
		
		}
	}

	cout << last <<"\n";
	cout << sum-cnt << "\n";
	cout << sum << " " << cnt;
}