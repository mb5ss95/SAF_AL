#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<string> result;
int N, c;

void run(int lv, string str) {
	string dat = "0123456789";
	if (lv == N) {
		result.push_back(str);
		return;
	}

	for (int i = 0; i < c; i++) {
		run(lv + 1, str + dat[i]);
	}
}

vector<vector<int>> get_startX() {
	vector<vector<int>> startX;
	for (int i = 0; i < result.size(); i++) {
		vector<int> temp;
		for (int j = 0; j < result[i].size(); j++) {
			temp.push_back(result[i][j] - '0');
		}
		startX.push_back(temp);
	}
	result.clear();

	return startX;
}

vector<vector<int>> get_map(int R, int C) {
	vector<vector<int>> map(R, vector<int>(C, 0));
	int temp;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> temp;
			map[i][j] = temp;
		}
	}
	return map;
}

vector<vector<int>> boom(vector<vector<int>> map, int y, int x) {
	struct node {
		int y, x;
		int how;
	};
	// all 
	// N
	// E
	// S
	// W

	// 위 오른쪽 아래 왼쪽

	queue<node> q;

	q.push({ y, x, map[y][x] });

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.how == 0) continue;
		map[now.y][now.x] = 0;
		//세로 조지기 - 위로
		for (int i = 1; i < now.how; i++) {
			int upup = now.y - i;
			if (upup < 0) continue;
			q.push({ upup, now.x, map[upup][now.x] });
		}
		//세로 조지기 - 아래로
		for (int i = 1; i < now.how; i++) {
			int down = now.y + i;
			if (down >= map.size()) continue;
			q.push({ down, now.x, map[down][now.x] });
		}
		//가로 조지기 - 왼쪽
		for (int i = 1; i < now.how; i++) {
			int left = now.x - i;
			if (left < 0) continue;
			q.push({ now.y, left, map[now.y][left] });
		}
		//가로 조지기 - 오른쪽
		for (int i = 1; i < now.how; i++) {
			int righ = now.x + i;
			if (righ >= map[0].size()) continue;
			q.push({ now.y, righ, map[now.y][righ] });
		}
	}

	/////////////
	//cout << "\n";
	//for (int i = 0; i < map.size(); i++) {
	//	for (int j = 0; j < map[i].size(); j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	return map;
}

vector<vector<int>> fresh_map(vector<vector<int>> map) {
	for (int i = 0; i < map[0].size(); i++) {
		for (int j = map.size() - 1; j > 0; j--) {
			if (map[j][i] == 0) {
				map[j][i] = map[j - 1][i];
				map[j - 1][i] = 0;
			}
		}
	}
	return map;
}

int crush_wall(vector<vector<int>> map, vector<int> startX) {
	int result = 0;
	for (int i = 0; i < startX.size(); i++) {
		for (int j = 0; j < map.size(); j++) {
			int target = map[j][startX[i]];
			if (target == 0) continue;
			//cout << target<<"\n";
			map = boom(map, j, startX[i]);
			break;
		}
		map = fresh_map(map);
		////////
		//cout << "\n";
		//for (int i = 0; i < map.size(); i++) {
		//	for (int j = 0; j < map[i].size(); j++) {
		//		cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		int h = 0;
	}

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 0) continue;
			result++;
		}
	}
	int dd = 2;
	return result;

}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int R, C;
		cin >> N >> C >> R;
		if (C > 10) c = 9;
		else {
			c = C;
		}
		run(0, "");
		vector<vector<int>> startX = get_startX();
		vector<vector<int>> map = get_map(R, C);

		int result = 2132131231;
		for (int i = 0; i < startX.size(); i++) {
			int temp = crush_wall(map, startX[i]);
			result = min(result, temp);
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}