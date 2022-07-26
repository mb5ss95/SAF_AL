#include <iostream>

using namespace std;

/*
0 1 2 3 4 5 5 4 3 2 1 0
*/

// ¿Á±Õ»£√‚
void  run(int x) {
	if (x == 6) return;
	cout << x << " ";
	run(x + 1);
	cout << x << " ";
	return;
}


int main() {
	int x = 0;


	run(0);

}