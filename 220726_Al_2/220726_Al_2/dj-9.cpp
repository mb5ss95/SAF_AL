#include <iostream>

using namespace std;



// 0~3 ���� 5���� ������ ����
// 0 0 0 0 0
// 0 0 0 0 1
// ....
// ....
// 3 3 3 3 3

// ���ڵ��� ����� ��
//char path[5];
//char name[10] = "ABTQ";

int path[5];

void run(int level) {
	// level �� ���� ���̸� ��Ÿ��
	if (level == 2) {
		for (int i = 0; i < 2; i++) cout << path[i] << " ";
		cout << "\n";
		return;
	}
	// �귱ġ�� ���� ���̸� ��Ÿ��
	for (int i = 0; i < 4; i++) {
		// ���ڵ��� ����� ��
		// path[level] = name[i];
		// ���ڵ��� ����� ��
		path[level] = i;
		run(level + 1);

	}
}


int main() {
	run(0);
}