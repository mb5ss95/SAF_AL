#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int arr[] = { 1,2,5,6,7,8,9,10,15,16,25,33,34,37,57,89 };

int bs(int s, int e, int target) {
	while (s <= e) {
		int mid = (s + e) / 2;

		if (arr[mid] == target) {
			return mid;
		}

		if (arr[mid] < target) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	return -1;
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int len = sizeof(arr) / sizeof(int);
	int ret = bs(0, len, 15);
	cout << ret<<"에서 발견";
}