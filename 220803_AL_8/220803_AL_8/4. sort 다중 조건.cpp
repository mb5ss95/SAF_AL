#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �����ϴµ� �켱 ����
// 1. ¦�� �켱
// 2. ������ �켱

bool compare(int t, int v) {
	// t�� �������� t�� v���� �켱������ �� ����? return 1
	// �ƴ� 0
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