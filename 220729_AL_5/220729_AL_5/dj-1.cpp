#include <iostream>
#include <string>

using namespace std;

int main() {
	string strs = "ABCATTTABCABC";
	string fstr = "ABC";
	int index = -1;

	while (1) {
		index = strs.find(fstr, ++index);
		if (index == -1) break;
		cout << index << " ";
	}


}