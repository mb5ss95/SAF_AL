#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[] = {5,6,7,8,3,2,5,2,1,6,7,8};
	int num = sizeof(arr) / sizeof(int);

	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	sort(arr, arr + num);
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	sort(arr, arr + num, greater<int>());

	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}