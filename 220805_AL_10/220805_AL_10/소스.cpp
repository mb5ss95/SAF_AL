#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int to;
	int len;
};

bool operator<(node a, node b) {
	return a.len < b.len;
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

		}
	}
}