#include <iostream>
#include <string>

using namespace std;

string str[] = { "bt", "kf", "ccc", "mom", "sk", "mc" };
int used[10];

void run(int lv,  string result) {
	if (lv == 3) {
		cout << result << "\n";
		result = "";
		return;
	}

	for (int i = 0; i < 6; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		run(lv + 1, result + str[i]);
		used[i] = 0;
	}
}


int main() {
	run(0,  "");
}