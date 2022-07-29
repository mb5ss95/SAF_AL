#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v(6);
int used[10];

// 모든 경로를 탐색
void run(int now) {
	cout << now << " ";
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (used[next] == 1) continue;
		used[next] = 1;
		run(next);
		used[next] = 0;
	}
}

int main() {
	v[1] = { 2, 4 };
	v[2] = { 5 };
	v[3] = { 1 };
	v[4] = { 3 };
	v[5] = { 1, 3 };

	used[1] = 1;
	run(1);
}