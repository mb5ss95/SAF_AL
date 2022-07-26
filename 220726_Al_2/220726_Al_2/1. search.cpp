#include <iostream>

using namespace std;

// 한 지점을 중심으로 주변을 탐색
int main() {
	int arr[4][5] = {
	{5,6,7,8,9},
	{1,1,1,1,1},
	{0,0,0,0,0},
	{1,1,1,1,1}
	};

	int r, c;
	int sum = 0;

	cin >> r >> c;

	arr[r][c];
	arr[r - 1][c + 1];
	arr[r + 1][c + 1];
	arr[r + 1][c - 1];
	arr[r - 1][c - 1];
	
	int dR[] = { 0,-1, 1, 1, -1 };
	int dC[] = { 0, 1, 1,-1, -1 };

	for (int i = 0; i < 5; i++) {
		int nextR = r + dR[i];
		int nextC = c + dC[i];

		if (nextR < 4 && nextR >= 0 && nextC < 5 && nextC >= 0) {
			sum = sum + arr[nextR][nextC];
		}
	}

	cout << sum;
}
