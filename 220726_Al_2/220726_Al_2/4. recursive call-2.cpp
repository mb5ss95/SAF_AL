#include <iostream>

using namespace std;

/*

2. ���� ��� ����

*/

void  run(int x) {
	if (x == 2) return; //�󸶳� ����?

	// �귣ġ ����(�󸶳� ���������)
	for (int i = 0; i < 2; i++) {
		run(x + 1);
		cout << "#";
	}

	return;
}


// ���ȣ��
int main() {

	run(0);

}