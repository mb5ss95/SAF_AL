#include <iostream>

using namespace std;

int arr[2][2] = { 
	{1,5},
	{1,1} 
};

int map[4][5] = {
	{1,5,4,9,9},
	{1,1,5,4,9},
	{1,1,1,1,5},
	{1,5,4,1,1}
};

int isSame(int dy, int dx) {
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			if (arr[y][x] != map[dy+y][dx+x]) return 0;
		}
	}
	return 1;
}


// °°³Ä?
int main() {
	int sum = 0;

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 4; c++) {
			if (isSame(r, c)) sum++;
		}
	}

	cout << sum << "°³";
}

