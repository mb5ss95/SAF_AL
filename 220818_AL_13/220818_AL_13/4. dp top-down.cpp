#include <iostream>
#include <vector>

using namespace std;

// 정답지 배열 "메모"를 만듬
// 이런 기법을 메모이제이션
// 탑다운 사용할땐 메모이제이션이 필수
// 메모이제이션을 해야 바텀업 같은 성능이 나옴
int memo[100];

int run(int th) {

	//run(th)에 대한 정답이 뭡니까?
	if (memo[th] != 0) return memo[th];

	if (th == 1) return 0;
	if (th == 2) return 1;

	int a = run(th - 2);
	int b = run(th - 1);

	memo[th] = a + b;
	return a + b;
}

// top - down
// 만약 정답을 알고 있는 함수
// 아직 안 만들었지만 정답이 무조건 나오는 함수가 있습니다.
int main() {
	cout << run(50);
}