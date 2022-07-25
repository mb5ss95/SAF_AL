#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// trace : 코드를 아주 디테일하게 하나하나 확인
	//		   코드를 '한줄 한줄' 직접 실행

	// break point : F9
	//				 코드를 어디에서 멈출지(한줄 한줄 실행하기 시작할 부분)
	// 디버깅 모드 : F5

	// step over : F10
	// step into : F11

	// resume : F5
	//			지금 코드부터 이어서 쭉 실행, 단 breakpoint를 만나면 스탑
	// 디버깅모드(trace) 종료 : shift + F5

	// 조사식 : 각각의 변수들이 어떻게 변해가는지 확인하기 용이한 창 (확인하고 싶은 내용을 이름에 입력하면 알아서 찾아서 나옴)
	// 디버그 -> 창 -> 조사식

	// 조사식에서 변수.b 하면 이진수로 볼 수 있음 (ex. a.b)
	int a = 1;

	for (int i = 0; i < 10; i++) {
		a = a + 2;
		cout << a << "\n";
	}

	return 0;
}