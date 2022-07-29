#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> vec;

// (((((^0^))((^^^)))(^_^)))))
string flesh(string str, string wht) {
	int fIdx, lIdx;
	int temp = 0;
	fIdx = str.find(wht, temp); // 0
	lIdx = fIdx; // 0
	while (1) {
		temp = str.find(wht, ++lIdx);
		if (temp != lIdx) {
			str.erase(fIdx + 1, lIdx - 1);
			break;
		}
	}


	return str;
}


int main() {
	string str;
	string fStr[] = { "((", "))", "^^^" };

	cin >> str;
	for (int i = 0; i < 1; i++) {
		str = flesh(str, fStr[i]);
		cout << str;
	}

}