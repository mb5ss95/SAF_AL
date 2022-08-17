#include <iostream>
#include <vector>

using namespace std;

struct node {
	int startY, startX;
	int endY, endX;
};

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> smap(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	int dsum = 0;

	for (int i = 1; i <= N; i++) {
		int rsum = 0;
		for (int j = 1; j <= N; j++) {
			rsum = rsum + map[i][j] + smap[i-1][j] - smap[i-1][j-1];
			smap[i][j] = rsum;
		}

	}

	for (int i = 0; i < M; i++) {
		int startY, startX, endY, endX;
		cin >> startY >> startX >> endY >> endX;

		int sum = smap[endY][endX] - smap[startY-1][endX] - smap[endY][startX-1] + smap[startY-1][startX-1];
		cout << sum << "\n";
	}
}