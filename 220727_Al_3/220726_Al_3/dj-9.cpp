#include <iostream>
#include <string>

using namespace std;

int main() {
	/*
	���� �Է¹ް�
	+ 100�� �մϴ�.
	ù��°�� ������ ���� ���
	*/

	int a;
	cin >> a;

	string str = to_string(a+100);
	int index = str.length() - 1;
	cout << str[0] << "\n";
	cout << str[index] << "\n";

}