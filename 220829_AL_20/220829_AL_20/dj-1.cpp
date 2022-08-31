#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int y, x;
	int num;
};

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int rc;
		cin >> rc;
		vector<vector<node>> v(rc, (vector<node> rc));
		
		int temp;
		for (int i = 0; i < rc; i++) {
			for (int j = 0; j < rc; j++) {
				cin >> temp;
			}
		}
	}
}