#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int num;
int result = -2134567890;
struct node {
	int day;
	int money;
};

vector<node> v(200);

void run(int th, int sum){
	if (th > num) {
		result = max(result, sum);
		return;
	}
	for (int i = th; i <= num; i++) {
		run(th + v[th].day, sum + v[th].money);
	}
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> num;

	for (int i = 1; i <= num; i++) {
		int day, money;
		cin >> day >> money;
		v[i] = { day, money };
	}
	int h = 9;
	run(1, 0);
	cout << result;
}