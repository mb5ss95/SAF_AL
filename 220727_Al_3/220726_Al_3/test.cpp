#include <iostream>
#include <string>

using namespace std;

// MPASSOHPASSpasSpassSFAILFFFFAILFAIL
int findStr(string str, string msg) {
	int cnt = 0;
	int index = -1;
	while (1) {
		index = str.find(msg, ++index);
		if (index == -1) break;
		cnt++;
	}
	return cnt;
}


int main() {
	string str;
	string datPass[] = { "pass", "pasS" };
	int passSum = 0;
	int failSum = 0;

	cin >> str;

	passSum = passSum + findStr(str, "Pass"); // 4
	failSum = failSum + findStr(str, "FAIL"); // 1
	int percent = (passSum * 100 / (passSum + failSum));

	cout << percent << "%";


}