#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[160] = { 0 };
int memo[160];
int num;
int maxi = -2147483647;

void run(int th, int sum) {
	if (th > num) {
		if (sum > maxi) maxi = sum;
		return;
	}

	sum = sum + map[th];
	run(th + 2, sum);
	run(th + 7, sum);
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> map[i];
	}
	run(0, 0);

	cout << maxi;
}