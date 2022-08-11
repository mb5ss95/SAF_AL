#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int y, x;
};

bool operator<(node a, node b) {
	return a.y < b.y;
}

int r, c;
vector<node> v; // 감염 지역
vector<node> z; // 미감염 지역


int run(vector<vector<int>> tmap, vector<node> temp) {
	for (node n : temp) {
		tmap[n.y][n.x] = 1;
	}
	int dy[] = { 1, -1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };

	priority_queue<node> q;

	for (int i = 0; i < v.size(); i++) {
		q.push({ v[i].y, v[i].x });
	}

	while (!q.empty()) {
		node now = q.top();
		q.pop();
		int startY = now.y;
		int startX = now.x;

		for (int j = 0; j < 4; j++) {
			int newY = startY + dy[j];
			int newX = startX + dx[j];

			if (newY < 0 || newX < 0 || newY >= r || newX >= c) continue;
			if (tmap[newY][newX] != 0) continue;

			tmap[newY][newX] = 2;
			q.push({ newY, newX });
		}
	}

	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (tmap[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

void dfs(Node now)
{
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	for (int i = 0; i < 4; i++)
	{
		int nr = now.row + dr[i];
		int nc = now.col + dc[i];
		if (MAP[nr][nc] != 0) continue; // 빈칸이 아니면 가지 못함
		if (visited[nr][nc]) continue; // 찾았떤 기록이 있으면 무시
		visited[nr][nc] = 1;
		blankCnt++;
		dfs({ nr, nc });
	}
}


void dfs(node now) {
	i
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	cin >> r >> c;
	vector<vector<int>> map(8, vector<int>(8, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int temp;
			cin >> temp;
			if (temp == 0) z.push_back({ i, j });
			else if (temp == 2) v.push_back({ i, j });
			map[i][j] = temp;
		}
	}
	int max = -21e8;
	for (int i = 0; i < z.size(); i++) {
		for (int j = i + 1; j < z.size(); j++) {
			for (int k = j + 1; k < z.size(); k++) {
				vector<node> temp;
				temp.push_back({ z[i].y, z[i].x });
				temp.push_back({ z[j].y, z[j].x });
				temp.push_back({ z[k].y, z[k].x });

				int cnt = run(map, temp);
				if (max < cnt) max = cnt;
			}
		}
	}

	cout << max;
}