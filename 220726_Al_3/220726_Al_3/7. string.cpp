#include <iostream>
#include <string> // c++용 string 클래스

//#include <cstring> //c언어 string.h
//#include <string.h> // strcmp, strlen 함수

using namespace std;

int main() {
	string str;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		cout << str[i];
	}


	// 밑에 방법 방법은 느림
	char buf[10] = "ABC";
	int n = strlen(buf); //내부에 반복문이 있음.
	for (int i = 0; i < n; i++) {
		cout << "#";
	}

	string str;
	str = "dsds" + "!23123"; // 안됨
	str = string("sdsad") + "SDsds"; //됨

	cout << str;
}