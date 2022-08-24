#include <iostream>
#include <map> //<---- bst
#include <unordered_map> //<---- hash

using namespace std;

int main() {

	int val[] = { 3,4,2,1,5 };

	unordered_map<int, int>um;
	for (int i = 0; i < 5; i++) {
		um[i] = val[i];
	}

	if (um.cout(5000)) cout << "gpod"; // 있는지 확인하고 싶으면

	if (um[5000] == 4000) { // 선언 안했는데 값이 추가됨
		cout << "굳";
	}

	cout << um[5000];

	return 0;
}