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

	if (um.cout(5000)) cout << "gpod"; // �ִ��� Ȯ���ϰ� ������

	if (um[5000] == 4000) { // ���� ���ߴµ� ���� �߰���
		cout << "��";
	}

	cout << um[5000];

	return 0;
}