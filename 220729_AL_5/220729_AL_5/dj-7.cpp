#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v(5);
int used[10];
int cnt = 0;
void run(int now) {
	if (now == 4) {
		cnt++;
		return;
	}


	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (used[next] == 1) continue;
		used[next] = 1;
		run(next);
		used[next] = 0;
	}
}


int main() {
	v[1] = { 2,3,4 };
	v[2] = { 3,4 };
	v[3] = { 1,4 };

	used[1] = 1;
	run(1);

	cout << cnt;
}