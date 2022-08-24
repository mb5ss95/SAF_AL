#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {

	string strs[] = { "huhu", "hot", "bts", "mc", "hot", "hot" };
	unordered_map<string, int> um;

	for (int i = 0; i < 6; i++) {
		um[strs[i]] = um[strs[i]] + 1;
	}

	string str;
	cin >> str;
	cout << um[str];
	int d = 0;
}