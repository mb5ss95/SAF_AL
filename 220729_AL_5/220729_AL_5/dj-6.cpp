#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> vec(7);

void run(int now) {
	cout << now << " ";
	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];

		run(next);
	}
}

int main() {
	vec[1] = { 2, 3, 4 };
	vec[3] = { 5, 6 };

	run(1);
}