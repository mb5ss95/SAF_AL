#include <iostream>

using namespace std;

/*
���� ��� ȣ��
0x769B0886(KernelBase.dll)��(Project1.exe��) ó������ ���� ���ܰ� �ֽ��ϴ�. 0xC00000FD: Stack overflow(�Ű� ����: 0x00000001, 0x00E72FFC). �߻�

1. ���� ��� ����

*/

void  run(int x) {
	if (x == 2) return;
	x++;
	run(x);
	return;
}


// ���ȣ��
int main() {

	run(0);

}