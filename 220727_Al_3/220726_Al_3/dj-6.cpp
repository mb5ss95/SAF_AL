#include <iostream>

using namespace std;

int used[10] = { 0 , };
int n;
int max = 0;

void run(int level) {
	if (level == n) {
		max++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		run(level + 1);
		used[i] = 0;
	}
}

int main() {
	// 입력과 출력이 10만개 이상 있을때 사용하셈
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	run(0);
	cout << max;
	return 0;
}