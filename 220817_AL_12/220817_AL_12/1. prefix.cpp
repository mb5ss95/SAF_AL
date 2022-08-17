#include <iostream>
#include <vector>

using namespace std;

int main() {
	int arr[] = { 4,2,5,1,1,2,3,1,4,1 };
	vector<int> v; // {4, 6, 11, 12, 13, 15, 18, 19, 22, 23}
	int alen = sizeof(arr) / sizeof(int);

	int *brr = new int[alen];
	for (int i : brr) {
		cout << i << " ";
	}
	int sum = 0;
	for (int i = 0; i < alen; i++) {
		sum = sum + arr[i];
		v.push_back(sum);
	}

	for (int i : v) {
		cout << i << " ";
	}
}