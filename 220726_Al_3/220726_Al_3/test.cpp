#include <iostream>

using namespace std;

int used[10];
int n;

void run(int lv) {
	if (lv == n) return;

	for (int i = 0; i < n; i++) {
		if () continue;

		run(lv + 1);
	}
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	run(0);

}