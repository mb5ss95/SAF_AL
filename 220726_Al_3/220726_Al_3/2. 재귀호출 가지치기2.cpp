#include <iostream>
using namespace std;

//branch = 4
//level = 2

char path[10];
// 들어갔다가 나오기
void run(int lev) {
	if (lev == 1 && path[0] == '3') return;
	if (lev == 1 && path[0] == '4') return;
	if (lev == 3) {
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < 4; i++) {
		path[lev] = 'A' + i;
		run(lev + 1);
		path[lev] = 0;
	}
}

int main() {
	run(0);

	return 0;
}