#include <iostream>
#include <string>
using namespace std;

int isValid(string email) {
	//1. @, . 대소문자 숫자로 구성되어있는지 확인
	for (int i = 0; i < email.size(); i++) {
		char ch = email[i];
		if (ch >= 'A' && ch <= 'Z') continue;
		if (ch >= 'a' && ch <= 'z') continue;
		if (ch >= '0' && ch <= '9') continue;
		if (ch == '@' || ch == '.') continue;
		return 0;
	}

	//2. @ . 이 각각 1개인지 검사
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < email.size(); i++) {
		if (email[i] == '@') cnt1++;
		if (email[i] == '.') cnt2++;
	}
	if (cnt1 != 1 || cnt2 != 1) return 0;

	//3. @ 다음에 . 이 나오는지 검사
	int a = email.find('@');
	int b = email.find('.', a + 1);
	if (b == -1) return 0;

	//4. @, . 이 각각 맨앞과 맨뒤면 탈락
	if (a == 0 || b == email.size() - 1) return 0;

	//5. @랑 . 사이에 문자가 존재
	if (a + 1 == b) return 0;

	return 1;
}

int main() {

	string email = "ABC@BBQ.com";

	if (isValid(email)) cout << "OK";
	else cout << "NO";

	return 0;
}