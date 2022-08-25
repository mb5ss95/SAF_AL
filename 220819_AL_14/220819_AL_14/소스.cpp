#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;


vector<vector<int>> v;
vector<int> used(10000);

int num;


void run(int lv, int sum, int cnt) {
	
	if (cnt == 5) {
		cout << "\n";
		return;
	}
	cout << lv << " ";
	for (int i = 0; i < v[lv].size(); i++) {
		if (v[lv][i] == 0) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		run(i, sum + v[lv][i], cnt +1);
		used[i] = 0;
	}
}


int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> num;
	vector<vector<int>> temp(num, vector<int>(num, 0));
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int a;
			cin >> a;
			temp[i][j] = a;
		}
	}
	v = temp;
	used[0] = 1;
	run(0, 0, 0);

}