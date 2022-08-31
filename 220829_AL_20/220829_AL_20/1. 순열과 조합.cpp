#include <iostream>

using namespace std;

int path[10];

int arr[3][3] = {
	1,2,3,
	4,5,7,
	8,10,15
};
/*
void run(int lv) {
	if (lv == 3) {
		for (int i = 0; i < 3; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < 3; i++) {
		path[lv] = arr[lv][i];
		run(lv + 1);
	}
}
*/


// 순열

void run(int lv) {
	if (lv == 3) {
		for (int i = 0; i < 3; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			path[lv] = arr[i][j];
			run(lv + 1);
		}
	}
}


// 조합
//void run(int lv, int si, int sj) {
//	if (lv == 3) {
//		for (int i = 0; i < 3; i++) {
//			cout << path[i] << " ";
//		}
//		cout << "\n";
//		return;
//	}
//	for (int i = si; i < 3; i++) {
//		for (int j = sj; j < 3; j++) {
//			path[lv] = arr[i][j];
//			run(lv + 1, i, j);
//		}
//	}
//}


int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	run(0);
}