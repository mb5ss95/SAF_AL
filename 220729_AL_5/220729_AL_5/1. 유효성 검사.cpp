#include <iostream>
#include <string>
using namespace std;

int isValid(string id) {
	//1. 대문자, 숫자로만 구성
	for (int i = 0; i < id.size(); i++) {
		char ch = id[i];
		if (ch >= 'A' && ch <= 'Z') continue;
		if (ch >= '0' && ch <= '9') continue;
		return 0;
	}

	//2. 8글자 미만
	if (id.size() > 6) return 0;

	//3. 첫글자 숫자 금자
	if (id[0] >= '0' && id[0] <= '9') return 0;


	return 1;
}

int main() {

	string id = "BBQKFC1";

	if (isValid(id)) cout << "yes";
	else cout << "no";

	return 0;
}