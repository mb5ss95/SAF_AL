#include <iostream>
#include <vector>
#include <string>

using namespace std;

string bbq = "ABC|BBQ|KFC|OKCASH";

vector<string> split(string gijun) {
	vector<string> list;

	int a = 0;
	int b = 0;
	string str = bbq + gijun;

	while (1) {
		b = str.find(gijun, a);
		if (b == -1) break;

		//¶âÀÚ
		int size = b - a;
		string temp = str.substr(a, size);
		list.push_back(temp);

		a = b + 1;
	}

	return list;
}

int main() {

	vector<string> list = split("|");

	return 0;
}