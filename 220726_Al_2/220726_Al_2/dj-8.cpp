#include <iostream>

using namespace std;

int arr[] = { 4,2,9,1,5 };

// ¿Á±Õ»£√‚
void  run(int x) {
	if (x == 5) {
		return;
	}
	cout << arr[x] << " ";
	run(x + 1);
	cout << arr[x] << " ";
	return;
}


int main() {
	int x = 0;

	run(0);
}