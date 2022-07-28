#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = "ABBBBBBKBCDNNNBNNNBBBCDASDWEQBBBBCD";
	string fstr = "BB";
	int cnt = 0;
	int index = -1;

	while (1) {
		index = str.find(fstr, ++index);
		if (index == -1) break;
		cnt++;
	}


	cout << cnt;
}
