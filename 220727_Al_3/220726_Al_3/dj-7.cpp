#include <iostream>

using namespace std;

int used[10] = {0,};
int path[10];
int n; // 던진 횟수
int m; // 출력 모양 1,

void run1(int level) {
	if (level == n) {
		for (int i = 0; i < n; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= 6; i++) {
		path[level] = i;
		run1(level + 1);
	}
}

void run2(int level, int start) {
	if (level == n) {
		for (int i = 0; i < n; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i <= 6; i++) {
		if (i != 0 && used[i-1] == 1) continue;
		used[i] = 1;
		path[level] = i;
		run2(level + 1, i);
		used[i] = 0;
	}
}

void run3(int level) {
	if (level == n) {
		for (int i = 0; i < n; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

		for (int i = 1; i <= 6; i++) {
			if (used[i] == 1) continue;
			used[i] = 1;
			path[level] = i;
			run3(level + 1);
			used[i] = 0;
		}
}

int main() {

	cin >> n >> m;
	if (m == 1) run1(0);
	else if(m == 2) run2(0, 1);
	else if (m == 3) run3(0);
}