#include <iostream>
#include <string>
using namespace std;

int isValid(string email) {
	//1. @, . ��ҹ��� ���ڷ� �����Ǿ��ִ��� Ȯ��
	for (int i = 0; i < email.size(); i++) {
		char ch = email[i];
		if (ch >= 'A' && ch <= 'Z') continue;
		if (ch >= 'a' && ch <= 'z') continue;
		if (ch >= '0' && ch <= '9') continue;
		if (ch == '@' || ch == '.') continue;
		return 0;
	}

	//2. @ . �� ���� 1������ �˻�
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < email.size(); i++) {
		if (email[i] == '@') cnt1++;
		if (email[i] == '.') cnt2++;
	}
	if (cnt1 != 1 || cnt2 != 1) return 0;

	//3. @ ������ . �� �������� �˻�
	int a = email.find('@');
	int b = email.find('.', a + 1);
	if (b == -1) return 0;

	//4. @, . �� ���� �Ǿհ� �ǵڸ� Ż��
	if (a == 0 || b == email.size() - 1) return 0;

	//5. @�� . ���̿� ���ڰ� ����
	if (a + 1 == b) return 0;

	return 1;
}

int main() {

	string email = "ABC@BBQ.com";

	if (isValid(email)) cout << "OK";
	else cout << "NO";

	return 0;
}