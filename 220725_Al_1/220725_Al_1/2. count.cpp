#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	int arr[10] = { 0, 9, 8, 1, 2, 3, 4, 5, 6, 7 };
	int brr[10] = { 0, };
	
	for (int i = 0; i < 10; i++ ) {
		brr[arr[i]] = i;
	}

	for (int i = 0; i < 10; i++) {
		cout << i << " : "<< brr[i] << "\n";
	}

	return 0;
}