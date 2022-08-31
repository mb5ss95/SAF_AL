#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>


using namespace std;

struct node {
	int y, x;
	int val;
};

vector<vector<node>> map;
vector <vector<node>> used;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };
int distanceD;

void action() {
	system("cls");
	for (int i = 0; i < used.size(); i++) {
		for (int j = 0; j < used[i].size(); j++) {
			cout << used[i][j].val << " ";
		}
		cout << "\n";
	}
	Sleep(500);
}

void run(node now, int K, int D) {
	if (now.y == 4 && now.x == 2) {
		int d = 9;
	}
	//action();
	for (int i = 0; i < 4; i++) {
		int ny = now.y + dy[i];
		int nx = now.x + dx[i];
		// 1  3 2
		if (ny < 0 || nx < 0 || ny >= map.size() || nx >= map.size()) continue;
		node next = map[ny][nx];
		if (next.val - K >= now.val) continue;
		if (used[ny][nx].val == -1) continue;
		used[ny][nx].val = -1;

		if (next.val < now.val) {
			run(next, K, D + 1);
		}
		else {
			int remain = map[ny][nx].val - now.val + 1;
			map[ny][nx].val = map[ny][nx].val - remain;
			run(map[ny][nx], 0, D + 1);
			map[ny][nx].val = map[ny][nx].val + remain;
		}
		used[ny][nx].val = next.val;
	}
	distanceD = max(D, distanceD);
	if (distanceD == 8) {
		int  h = 0;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	freopen_s(new FILE*, "sample.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		int N, K, temp;
		cin >> N >> K; // 5 1

		vector<vector<node>> tempV(N, vector<node>(N));

		int maxi = -21321;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> temp;
				tempV[i][j] = { i,j,temp };
				maxi = max(maxi, temp);
			}
		}
		distanceD = -213123;
		used = tempV;
		map = tempV;
		used[2][3].val = -1;
		run(tempV[2][3], K, 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tempV[i][j].val != maxi) continue;
				distanceD = -213123;
				used = tempV;
				map = tempV;
				used[i][j].val = -1;
				run(tempV[i][j], K, 1);
			}
		}

		cout << "#" << tc << " " << distanceD << "\n";
	}

	return 0;
}