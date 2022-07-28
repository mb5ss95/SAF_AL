#include <iostream>

using namespace std;

char ch[10];

// 주사위 n개 던져서 합 구하기
// 합이 x미만만 출력
// 가지치기

void run(int level, int sum) {

	//2번 방식, 이게 더 간단한듯
	//if (sum >= 10) return;
	if (level == 3) {
		cout << ch << " " << sum << "\n";
		return;
	}
	for (int i = 1; i <= 6; i++) {
		if (sum + i >= 10) continue;
		ch[level] = '0' + i;
		run(level + 1, sum + i);
	}
}

int main() {

	run(0, 0);
}