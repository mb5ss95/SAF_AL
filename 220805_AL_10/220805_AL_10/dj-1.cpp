#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct info {
	int y, x;
	int num;
};

bool operator<(info a, info b) {
	if (a.num > b.num) return 0;
	if (a.num < b.num) return 1;

	return 0;
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	priority_queue<info> pq;
	vector<vector<int>> map;
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		vector<int> temp;
		for (int j = 0; j < num; j++) {
			int num;
			cin >> num;
			temp.push_back(num);
			pq.push({ i, j, num });
		}
		map.push_back(temp);
	}

	int dy[] = { 0,-1,0,1,0 };
	int dx[] = { 0,0,1,0,-1 };

	while (!pq.empty()) {
		info now = pq.top();
		pq.pop();

		for (int i = 0; i < 5; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= num || nx >= num) continue;
			now.num = -1;
		}
	}

}