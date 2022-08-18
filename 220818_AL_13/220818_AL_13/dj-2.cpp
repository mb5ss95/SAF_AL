#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[100] = { 0 };
int memo[100] = { 0 };
int a = 2;
int b = 7;
int num;
void run(int th) {
	if (th >= num) {
		return;
	}


	if (memo[th + a] < map[th + a] + memo[th]) memo[th + a] = map[th + a] + memo[th];
	run(th + a);

	if (memo[th + b] < map[th + b] + memo[th]) memo[th + b] = map[th + b] + memo[th];
	run(th + b);
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> map[i];
		memo[i] = -2147444444;
	}
	run(0);
	
	int y = 8;
	sort(memo, memo+num+1, greater<int>());

	cout << memo[0];
}