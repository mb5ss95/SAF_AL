#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	string strs[] = { "000", "111", "222", "333", "444", "555", "666", "777", "888", "999" };
	int num;
	cin >> num;
	
	string str = "";
	for (int i = 0; i < num; i++) {
		string temp;
		cin >> temp;
		str = str + temp;
	}

	for (int i = 0; i < 10; i++) {
		int index = 0;
		while (1) {
			index = str.find(strs[i], index);
			if (index == -1) break;
			str.erase(index, 3);
		}
	}
	vector<int> result;
	for (int i = 0; i < str.length(); i++) {
		result.push_back(str[i]-'0');
	}
	
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}

