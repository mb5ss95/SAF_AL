#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	bool flag = true;

	cin >> str;

	if ('0' <= str[0] && str[0] <= '9') {
		flag = false;
	}
	else if(str.length() >= 8) flag = false;

	for (char i : str) {
		if ('A' > i && i > 'Z') {
			flag = false;
			break;
		}
		else if ('0' > i && i > '9') {
			flag = false;
			break;
		}
		else if ('a' <= i && i <= 'z') {
			flag = false;
			break;
		}
	}

	if(flag) cout << "YES";
	else cout << "NOOOOOOOOOOOOOOOOOO";
}