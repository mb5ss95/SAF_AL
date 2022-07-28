#include <iostream>

using namespace std;

int used[10] = { 0 };
int path[10];


// 중복된 숫자 없애기
// 완전 순열
void run(int level) {
	if (level == 3) {
		for (int i = 0; i < 3; i++) cout << path[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < 6; i++) {
		if (used[i] == 1) continue; // 이미 갔었나?
		used[i] = 1; // 체크하고 들어간다
		path[level] = i;
		run(level + 1);
		used[i] = 0; // 갔다와서 지운다

	}
}

int main() {
	run(0);
}