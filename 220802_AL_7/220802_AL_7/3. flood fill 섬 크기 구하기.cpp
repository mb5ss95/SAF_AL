#include <iostream>
#include <queue>
#include <Windows.h>

using namespace std;

int map[5][7] = {
	1,1,1,1,1,1,1,
	0,0,0,0,0,0,1,
	1,1,0,1,0,1,1,
	1,0,0,0,0,1,1,
	1,1,1,1,1,1,1
}; //0, 0을 포함한 섬의 크기는? = 13
int dy[] = { -1, 0, 1, 0 };
int dx[] = {  0, 1, 0,-1 };

struct node {
	int y, x;
	int level;
};

void action() {
	system("cls");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	Sleep(1000);
}

int main() {
	int fy = 0;
	int fx = 0;
	int cnt = 0;

	queue<node> q;
	q.push({ fy,fx,1 });
	map[fy][fx] = -1;

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		action();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= 5 || nx < 0 || nx >= 7) continue;
			if (map[ny][nx] < 1) continue;

			map[ny][nx] = -1;
			q.push({ ny, nx, now.level + 1 });
		}
		cnt++;
	}

	cout << cnt;

	return 0;
}