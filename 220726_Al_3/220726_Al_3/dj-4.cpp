#include <iostream>

using namespace std;

char ch[10];

// �ֻ��� n�� ������ �� ���ϱ�
// ���� x�̸��� ���
// ����ġ��

void run(int level, int sum) {

	//2�� ���, �̰� �� �����ѵ�
	//if (sum >= 10) return;
	if (level == 3) {
		cout << ch << " " << sum << "\n";
		return;
	}
	for (int i = 1; i <= 6; i++) {
		if (sum + i >= 10) continue;
		ch[level] = '0' + i;
		run(level + 1, sum + i);
	}
}

int main() {

	run(0, 0);
}