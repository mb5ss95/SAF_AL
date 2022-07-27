#include <iostream>
using namespace std;

//branch = 4
//level = 2

char path[3];
// 이전의 숫자가 중복되면 pass
// 1번과 2번 버전이 다름

void run(int lev) {
	// 2번 버전
	if (lev >= 2 && path[lev - 1] == path[lev - 2]) return;
	if (lev == 3) {
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < 4; i++) {
		// 1번 버전
		//if (lev != 0 && path[lev - 1] == '0' + i) continue;
		path[lev] =  '0' + i;
		run(lev + 1);
	}
}

int main() {
	run(0);

	return 0;
}