#include <iostream>
using namespace std;

//branch = 4
//level = 2

char path[10];
// 들어가기전에 차단
void run(int lev) {
	if (lev == 3) {
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (lev == 0 && i == 2) continue;
		if (lev == 0 && i == 3) continue;
		path[lev] = 'A' + i;
		run(lev + 1);
		path[lev] = 0;
	}
}

int main() {
	run(0);

	return 0;
}