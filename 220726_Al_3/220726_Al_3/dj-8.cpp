#include <iostream>
#include <string>

using namespace std;


int main() {
	string str[3] = {
		"arwqrqa",
		"basdas",
		"cdsadc"
	};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < str[2-i].length(); j++) {
			cout << str[2 - i][str[2 - i].length() - j - 1] << " ";
		}
		cout << "\n";
	}
}