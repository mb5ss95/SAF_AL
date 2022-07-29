#include <iostream>
#include <string>
using namespace std;

int isValid(string id) {
	//1. �빮��, ���ڷθ� ����
	for (int i = 0; i < id.size(); i++) {
		char ch = id[i];
		if (ch >= 'A' && ch <= 'Z') continue;
		if (ch >= '0' && ch <= '9') continue;
		return 0;
	}

	//2. 8���� �̸�
	if (id.size() > 6) return 0;

	//3. ù���� ���� ����
	if (id[0] >= '0' && id[0] <= '9') return 0;


	return 1;
}

int main() {

	string id = "BBQKFC1";

	if (isValid(id)) cout << "yes";
	else cout << "no";

	return 0;
}