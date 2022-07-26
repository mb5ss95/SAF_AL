#include <iostream>

using namespace std;

/*
ㅇ
2. 무한 재귀 막기

*/

void  run(int x) {
	if (x == 2) return;
	run(x + 1);
	run(x + 1);
	return;
}


// 재귀호출
int main() {

	run(0);

}