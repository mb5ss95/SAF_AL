#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[10] = { 1,5,7,7,3,0,8,2 };

	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	// 둘다 같은 의미
	sort(&arr[0], &arr[8]);
	// sort(arr, arr + 8);

	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	// 내림차순으로 출력
	int brr[10] = { 1,5,7,7,3,0,8,2 };
	sort(brr, brr + 8, greater<int>());

	for (int i = 0; i < 8; i++) {
		cout << brr[i] << " ";
	}
}