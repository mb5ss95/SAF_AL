#include <iostream>

using namespace std;
int arr[4][5] = {
	{4,5,1,-3,2},
	{1,-1,3,-1,5},
	{4,2,-5,6,-9},
	{-1,-1,-2,5,7}
};
// 21¾ï
// 21e8 
int used[10] = { 0, };
int min = 999999999;

void run(int level, int mul) {
	if (level == 4) {
		if (min > mul) min = mul;
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		run(level + 1, mul*arr[level][i]);
		used[i] = 0;
	}
}

int main() {
	run(0, 1);
	cout << min;
}
