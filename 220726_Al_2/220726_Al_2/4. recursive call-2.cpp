#include <iostream>

using namespace std;

/*

2. 무한 재귀 막기

*/

void  run(int x) {
	if (x == 2) return; //얼마나 들어가냐?

	// 브랜치 개수(얼마나 뻗어나가느냐)
	for (int i = 0; i < 2; i++) {
		run(x + 1);
		cout << "#";
	}

	return;
}


// 재귀호출
int main() {

	run(0);

}