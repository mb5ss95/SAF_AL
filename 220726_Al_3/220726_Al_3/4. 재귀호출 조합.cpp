#include <iostream>

using namespace std;

//중복 순열

int n = 3;
char path[10];

void run(int level, int start) {
	if (level == n) return;

	for (int i = start; i < 6; i++) {
		path[i] = '0' + i;
		run(level + 1, i);

	}
}

int main() {
	run(0, 1);
}