#include <iostream>
#include <queue>
#include <Windows.h>

using namespace std;

struct node {
	int y, x;
	int level;
};

int map[10][10] = {0};
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void action() {
	system("cls");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	Sleep(1000);
}


int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	int h, w;
	cin >> h >> w;


	queue<node> q;

	int y, x;
	int last = 0;
	cin >> y >> x;

	map[y][x] = 1;
	q.push({ y,x,1 });

	cin >> y >> x;

	map[y][x] = 1;
	q.push({ y,x,1 });

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		action();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (map[ny][nx] >= 1) continue;

			map[ny][nx] = 1;
			q.push({ ny, nx, now.level + 1 });
			last = now.level + 1;
		}
	}

	cout << last;

}