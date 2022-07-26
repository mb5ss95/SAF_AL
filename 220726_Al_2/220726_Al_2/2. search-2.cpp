#include <iostream>

using namespace std;

int arr[4][5] = {
	{5,6,7,8,9},
	{1,1,1,1,1},
	{2,2,2,2,2},
	{1,1,1,1,1}
};

int getJumsu(int r, int c) {
	int dR[] = { 0,-1,0,1,0 };
	int dC[] = { 0,0,1,0,-1 };
	int mul = 1;


	for (int i = 0; i < 5; i++) {
		int nR = r + dR[i];
		int nC = c + dC[i];

		if (nR < 4 && nR >= 0 && nC < 5 && nC >= 0) mul = mul * arr[nR][nC];
	}

	return mul;
}

int main() {

	int max = 0;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 5; c++) {
			int ret = getJumsu(r, c);
			if (ret > max) max = ret;
		}
	}
	cout << max;
}