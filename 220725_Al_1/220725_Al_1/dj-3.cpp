#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[] = { 15, 30, 15, 15, 30, 5, 9 };
	int brr[101] = { 0, };
	for (int i = 0; i < 7; i++) {
		brr[arr[i]]++;
	}

	int max = 0;
	for (int i : brr) {
		if (max < i) max = i;
	}

	cout << max;

	return 0;
}