#include <iostream>

using namespace std;

int used[10] = { 0 };
int path[10];


// �ߺ��� ���� ���ֱ�
// ���� ����
void run(int level) {
	if (level == 3) {
		for (int i = 0; i < 3; i++) cout << path[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < 6; i++) {
		if (used[i] == 1) continue; // �̹� ������?
		used[i] = 1; // üũ�ϰ� ����
		path[level] = i;
		run(level + 1);
		used[i] = 0; // ���ٿͼ� �����

	}
}

int main() {
	run(0);
}