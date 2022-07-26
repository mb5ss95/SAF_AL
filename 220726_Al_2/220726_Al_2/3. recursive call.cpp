#include <iostream>

using namespace std;

/*
무한 재귀 호출
0x769B0886(KernelBase.dll)에(Project1.exe의) 처리되지 않은 예외가 있습니다. 0xC00000FD: Stack overflow(매개 변수: 0x00000001, 0x00E72FFC). 발생

1. 무한 재귀 막기

*/

void  run(int x) {
	if (x == 2) return;
	x++;
	run(x);
	return;
}


// 재귀호출
int main() {

	run(0);

}