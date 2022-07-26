#include <iostream>

using namespace std;

// function
int fac(int arr1[], int arr2[]) {
	for (int i = 0; i < 4; i++) {
		if (arr1[i] != arr2[i]) {
			return 0;
		}
	}

	return 1;
}

// flag
// 같은 배열인지 확인하기
int main() {
	int arr1[] = { 1,5,4,9 };
	int arr2[] = { 1,5,7,9 };
	int result = 1;

	for (int i = 0; i < 4; i++) {
		if (arr1[i] != arr2[i]) {
			result = 0;
			break;
		}
	}

	cout << result << endl;

	cout << fac(arr1, arr2);
}