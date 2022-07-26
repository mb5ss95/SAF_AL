#include <iostream>
using namespace std;

int arr[4] = { 1, 5, 4, 9 };
int map[4][5] = {
	1, 5, 4, 9, 9,
	1, 1, 5, 4, 9,
	1, 1, 1, 1, 1,
	1, 5, 4, 9, 1
};

int isSame(int dy, int dx) {
	for (int i = 0; i < 4; i++) {
		if (arr[i] != map[dy][dx + i]) return 0;
	}
	return 1;
}

int main() {

	int cnt = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x <= 1; x++) {
			cnt += isSame(y, x);
		}
	}
	cout << cnt;


	return 0;