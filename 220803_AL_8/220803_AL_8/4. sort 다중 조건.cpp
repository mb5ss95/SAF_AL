#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬하는데 우선 순위
// 1. 짝수 우선
// 2. 작은수 우선

bool compare(int t, int v) {
	// t를 기준으로 t가 v보다 우선순위가 더 높다? return 1
	// 아님 0
	if (t % 2 == 0 && v % 2 == 1) return 1;
	if (t % 2 == 1 && v % 2 == 0) return 0;

	return t < v;
}

int main() {
	vector<int> vec = {2,7,5,3,5,8,9,2,1,2,3,9,0};


	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";

}