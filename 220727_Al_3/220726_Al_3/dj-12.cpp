#include <iostream>
#include <string>

using namespace std;

string fstr = "gold";

int findGold(string str) {
	int index = -1;
	int result = 0;
	while (1) {
		index = str.find(fstr, ++index);
		if (index == -1) break;
		result++;
	}
	

	return result;
}

int main() {
	string strs[5] = {
		"gold312gold",
		"gol$!@goldDgold",
		"gold",
		"gggggold!@#gold"
	};

	int cnt = 0;

	for (int i = 0; i < 5; i++) {
		cnt = cnt + findGold(strs[i]);
	}

	cout << cnt;
}
