#include <iostream>

using namespace std;

char ch[10];

// 주사위 n개 던져서 합 구하기

void run(int level, int sum) {
	if (level == 3) {
		cout << ch << " " << sum << "\n";
		return;
	}
	for (int i = 1; i <= 6; i++) {
		ch[level] = '0' + i;
		run(level + 1, sum + i);
	}
}

int main() {

	run(0, 0);
}