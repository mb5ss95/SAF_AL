#include <iostream>
using namespace std;

//branch = 4
//level = 2

char path[3];
// ������ ���ڰ� �ߺ��Ǹ� pass
// 1���� 2�� ������ �ٸ�

void run(int lev) {
	// 2�� ����
	if (lev >= 2 && path[lev - 1] == path[lev - 2]) return;
	if (lev == 3) {
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < 4; i++) {
		// 1�� ����
		//if (lev != 0 && path[lev - 1] == '0' + i) continue;
		path[lev] =  '0' + i;
		run(lev + 1);
	}
}

int main() {
	run(0);

	return 0;
}