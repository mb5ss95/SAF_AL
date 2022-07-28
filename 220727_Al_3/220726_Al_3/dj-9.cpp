#include <iostream>
#include <string>

using namespace std;

int main() {
	/*
	수를 입력받고
	+ 100을 합니다.
	첫번째와 마지막 수를 출력
	*/

	int a;
	cin >> a;

	string str = to_string(a+100);
	int index = str.length() - 1;
	cout << str[0] << "\n";
	cout << str[index] << "\n";

}