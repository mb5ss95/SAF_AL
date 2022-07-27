#include <iostream>
using namespace std;

//branch = 4
//level = 2

char path[10];

void run(int lev) {
	if (lev == 2) {
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