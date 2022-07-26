#include <iostream>

using namespace std;

/*
9 8 7 6 5 6 7 8 9
*/

// ¿Á±Õ»£√‚
void  run(int x) {
	cout << x << " ";
	if (x == 5) {
		return;
	}
	run(x - 1);
	cout << x << " ";
	return;
}


int main() {
	int x = 0;

	run(9);
}