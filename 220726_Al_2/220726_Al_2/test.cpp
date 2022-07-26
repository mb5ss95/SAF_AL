#include <iostream>

using namespace std;

int MAP[5][5] = {
	{3, 3, 5, 3, 1},
	{2, 2, 4, 2, 6},
	{4, 9, 2, 3, 4},
	{1, 1, 1, 1, 1},
	{3, 3, 5, 9, 2}
};

int sum(int y, int x) {
	int dy[] = { -1,1,1,-1 };
	int dx[] = { 1,1,-1,-1 };
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
			ret = ret + MAP[ny][nx];
		}
	}

	return ret;

}

int main() {
	/*
	y-1 x
	y x+1
	y+1 x
	y x-1
	*/
	int mi, mj;
	int max = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int temp = sum(i, j);
			if (max < temp) {
				mi = i;
				mj = j;
			}
		}
	}

	cout << mi << " " << mj;
}