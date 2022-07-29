#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> vec(6);
int used[10];

// 모든 노드를 1회씩 탐색
void run(int now) {
	cout << now << " ";
	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];
		if (used[next] == 1) continue;
		used[next] = 1;
		run(next);
	}
}

int main() {
	vec[1] = { 2 };
	vec[2] = { 3, 4 };
	vec[3] = { 4 };
	vec[4] = { 1 };

	used[1] = 1;
	run(1);

}