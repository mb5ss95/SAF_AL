#include <iostream>
#include <string>
using namespace std;
string bbq = "ABC##KFC##BTS##KFC####KFC####KFC";

void replace(string before, string after) {

	int a = 0;
	while (1) {
		a = bbq.find(before, a);
		if (a == -1) break;

		bbq.erase(a, before.size());
		bbq.insert(a, after);

		a++;
	}
}

int main() {

	//KFC ��´ܾ MC ���� (KFC�� �������� ������ �� �ִ�)

	cout << bbq << '\n';
	replace("KFC", "MC");
	cout << bbq << '\n';
	return 0;
}