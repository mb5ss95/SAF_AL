#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct node {
	string name;
	int y, x;
};
/*
   -1 done
	0 none
	1 wall
	2 garo
	3 sero
	4 degak
*/
int num;

bool checkWall(vector<vector<node>> map, node now, int idx) {

	if (now.name == "garo" && idx == 0) {
		if (map[now.y][now.x + 1].name == "wall") return true;
	}
	if (now.name == "garo" && idx == 1) {
		if (map[now.y][now.x + 1].name == "wall" || map[now.y + 1][now.x + 1].name == "wall" || map[now.y + 1][now.x].name == "wall") return true;
	}
	if (now.name == "sero" && idx == 0) {
		if (map[now.y + 1][now.x].name == "wall") return true;
	}
	if (now.name == "sero" && idx == 1) {
		if (map[now.y][now.x + 1].name == "wall" || map[now.y + 1][now.x + 1].name == "wall" || map[now.y + 1][now.x].name == "wall") return true;
	}
	if (now.name == "degak" && idx == 0) {
		if (map[now.y][now.x + 1].name == "wall") return true;
	}
	if (now.name == "degak" && idx == 1) {
		if (map[now.y][now.x + 1].name == "wall" || map[now.y + 1][now.x + 1].name == "wall" || map[now.y + 1][now.x].name == "wall") return true;
	}
	if (now.name == "degak" && idx == 2) {
		if (map[now.y + 1][now.x].name == "wall") return true;
	}

	return false;
}

string getName(string name, int idx) {
	if (name == "garo" && idx == 0) return "garo";
	if (name == "garo" && idx == 1) return "degak";
	if (name == "sero" && idx == 0) return "sero";
	if (name == "sero" && idx == 1) return "degak";
	if (name == "degak" && idx == 0) return "garo";
	if (name == "degak" && idx == 1) return "degak";
	if (name == "degak" && idx == 2) return "sero";

	return "-1";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample.txt", "r", stdin);

	cin >> num;

	vector<vector<node>> map(num, vector<node>(num));
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int temp;
			cin >> temp;
			if(temp == 1) map[i][j] = { "wall", i, j };
			else map[i][j] = { "none", i, j };
		}
	}


	queue<node> q;
	q.push({ "garo", 0, 1 });

	vector<int> garoDy = { 0, 1 };
	vector<int> garoDx = { 1, 1 };
	vector<int> seroDy = { 1, 1 };
	vector<int> seroDx = { 0, 1 };
	vector<int> degakDy = { 0, 1, 1 };
	vector<int> degakDx = { 1, 1, 0 };

	int cnt = 0;
	while (!q.empty()) {
		vector<int> dy;
		vector<int> dx;
		node now = q.front();
		q.pop();

		if (now.y == num - 1 && now.x == num - 1) cnt++;

		if (now.name == "garo") {
			dy = garoDy;
			dx = garoDx;
		}
		else if (now.name == "sero") {
			dy = seroDy;
			dx = seroDx;
		}
		else if (now.name == "degak") {
			dy = degakDy;
			dx = degakDx;
		}

		for (int i = 0; i < dy.size(); i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny >= num || nx >= num) continue;

			bool flag = checkWall(map, now, i);
			if (flag) continue;

			string nextName = getName(now.name, i);
			q.push({ nextName, ny, nx });
		}
	}
	cout << cnt;

}