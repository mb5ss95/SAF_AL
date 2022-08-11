#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct info {
	int y, x;
	int num;
};




int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);


	int num;
	cin >> num;
	vector<vector<info>> v(num + 1, vector<info>(num + 1));
	
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int temp;
			cin >> temp;
			v[i][j] = { i,j,temp };
		}
	}

	int dy[] = { 0, -1, 0, 1, 0 };
	int dx[] = { 0, 0, 1, 0, -1 };
	int cnt = 0;
	int HP = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j].num == -1) {
				cnt++;
				continue;
			}
			for (int k = 0; k < 5; k++) {
				int ny = v[i][j].y + dy[k];
				int nx = v[i][j].x + dx[k];

				if (ny < 0 || nx < 0 || nx >= num || ny >= num) continue;
				if (v[ny][nx].num == -1) continue;
				HP++;
				v[ny][nx].num = -1;
			}
		}
	}
	cout << HP << "n" << cnt;;
};
