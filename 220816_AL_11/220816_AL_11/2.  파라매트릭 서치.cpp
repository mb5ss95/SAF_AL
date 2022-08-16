#include <iostream>
#include <string>

using namespace std;

int bs(string str, int s, int e, char ch) {
	int last = -1;
	while (s <= e) {
		int mid = (s + e) / 2;

		if (str[mid] == ch) {
			last = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return last;
}

int main() {
	string str = "######____";
	char target = '#';

	int lastIdx = bs(str, 0, str.length() - 1, target);
	cout << (lastIdx + 1) * 100 / str.length() << "%";
}