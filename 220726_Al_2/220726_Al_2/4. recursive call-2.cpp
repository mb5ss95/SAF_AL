#include <iostream>

using namespace std;

/*
��
2. ���� ��� ����

*/

void  run(int x) {
	if (x == 2) return;
	run(x + 1);
	run(x + 1);
	return;
}


// ���ȣ��
int main() {

	run(0);

}