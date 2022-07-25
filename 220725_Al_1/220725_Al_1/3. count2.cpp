#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	/*
	  index에 인접한 1을 찾기
	*/
	int arr[10] = {0,1,0,0,1,1,0,1,0,1};
	int index;
	int answer = 0;

	cin >> index;
	/* 더러움
	if (index >= 1 && arr[index - 1]) answer++;
	if (arr[index] != 0) answer++;
	if (index <= 8 && arr[index + 1]) answer++;
	*/
	int d[] = { -1, 0, 1 };
	for (int i = 0; i < 3; i++) {
		int nextIndex = index + d[i];
		if (arr[nextIndex] != 0) answer++;

	}

	return 0;
}