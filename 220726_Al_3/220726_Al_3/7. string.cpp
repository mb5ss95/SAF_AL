#include <iostream>
#include <string> // c++�� string Ŭ����

//#include <cstring> //c��� string.h
//#include <string.h> // strcmp, strlen �Լ�

using namespace std;

int main() {
	string str;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		cout << str[i];
	}


	// �ؿ� ��� ����� ����
	char buf[10] = "ABC";
	int n = strlen(buf); //���ο� �ݺ����� ����.
	for (int i = 0; i < n; i++) {
		cout << "#";
	}

	string str;
	str = "dsds" + "!23123"; // �ȵ�
	str = string("sdsad") + "SDsds"; //��

	cout << str;
}