#include <iostream>
#include <queue>


using namespace std;

struct node {
	int y, x;
};

int arr[100][150] = { 0 };
int N, M;
int cnt = 0;


void run(int y, int x) {
	int dy[] = { 0, -1, 0, 1, 0 };
	int dx[] = { 0, 0, 1, 0, -1 };
	bool flag = false;

	queue<node> q;
	q.push({ y, x });

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 5; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (arr[ny][nx] == 2) flag = true;
			if (arr[ny][nx] < 1) continue;
			arr[ny][nx] = -1;
			q.push({ ny, nx });
		}
	}
	arr[y][x] = -1;
	if (flag) cnt++;
}


int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] < 1) continue;
			run(i, j);
		}
	}

	cout << cnt;
}