#include <iostream>
#include <queue>
#include<vector>
using namespace std;

/*
16 14 1 8
5 10 7 3
13 2 9 6
12 11 4 15
*/

vector<vector<int>> vec;

struct info {
	int y, x;
	int num;
};

bool operator<(info v, info t) {
	if (v.num < t.num) return 0;
	if (v.num > t.num) return 1;
	return 0;
}

int main()
{
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	
	priority_queue<info> q;

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		vector<int> temp = {};
		vec.push_back(temp);
		for (int j = 0; j < num; j++) {
			int num;
			cin >> num;
			vec[i].push_back(num);
			q.push({ i,j,num });
		}
	}
	int dy[] = {0, -1, 0, 1, 0 };
	int dx[] = {0, 0, 1, 0, -1 };
	int count = 0;
	bool flag, flag2;

	while (!q.empty()) {
		info now = q.top();
		q.pop();
		flag = true;
		flag2 = true;
		for (int i = 0; i < 5; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= num || nx >= num) continue;
			if (vec[ny][nx] == -1) continue;
			vec[ny][nx] = -1;

			if (flag) {
				count++;
				flag = false;
			}
		}
		if (flag) {
			count++;
			flag = false;
		}
	}

	cout << count;
	


	return 0;
}