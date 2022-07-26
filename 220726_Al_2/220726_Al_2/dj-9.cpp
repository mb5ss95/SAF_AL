#include <iostream>

using namespace std;



// 0~3 까지 5개의 길이의 순열
// 0 0 0 0 0
// 0 0 0 0 1
// ....
// ....
// 3 3 3 3 3

// 문자들의 경우의 수
//char path[5];
//char name[10] = "ABTQ";

int path[5];

void run(int level) {
	// level 은 가로 길이를 나타냄
	if (level == 2) {
		for (int i = 0; i < 2; i++) cout << path[i] << " ";
		cout << "\n";
		return;
	}
	// 브런치는 세로 길이를 나타냄
	for (int i = 0; i < 4; i++) {
		// 문자들의 경우의 수
		// path[level] = name[i];
		// 숫자들의 경우의 수
		path[level] = i;
		run(level + 1);

	}
}


int main() {
	run(0);
}