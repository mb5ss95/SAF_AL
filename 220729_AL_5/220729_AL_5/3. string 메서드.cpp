#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str = "012345";

	// ���ڿ� ����, 3�� �ε����� AAA����
	str.insert(3, "AAA"); // 012AAA345
	cout << str << "\n";
	// ���ڿ� �����, 3�� �ε������� 4���� ������
	str.erase(3, 4);
	cout << str << "\n";
}