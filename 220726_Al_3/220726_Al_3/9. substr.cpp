#include <iostream>
#include <string>

using namespace std;


int main() {
	string str = "ABCDEFG";

	/*
	���ڿ��� pos ��° ���� ���� count ���� ��ŭ�� ���ڿ��� �����Ѵ�. 
	���࿡, ���ڷ� ���޵� �κ� ���ڿ��� ���̰� ���ڿ� ���� ��ٸ�, �� �̻��� ��ȯ���� �ʰ� ���ڿ��� �� ������ �����Ѵ�.

	str.substr(pos, count)
	pos : ù��° ������ ��ġ (���� ���ڿ�����)
	count : �κ� ���ڿ��� ���� --> endIndex - startIndex - 1
	*/
	string temp = str.substr(3, 3); // DE
	cout << temp << "\n";

	int startIndex = str.find("D");
	int endIndex = str.find("E");
	string temp2 = str.substr(0, 2);
	cout << temp2 << "\n";



}