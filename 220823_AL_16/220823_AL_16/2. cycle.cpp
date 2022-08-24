#include <iostream>
#include <vector>

using namespace std;

int parents[100];

int Find(int now) {
	if (parents[now] == now) return now;

	return parents[now] = Find(parents[now]);
}

void Union(int a, int b) {
	int pA = Find(a);
	int pB = Find(b);

	if (pA == pB) return;

	parents[pB] = pA;
}


int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;

	vector<vector<int>> map(num, vector<int>(num, 0));

	for (int i = 0; i < num; i++) parents[i] = i;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			if (map[i][j] == 0) continue;

			if (Find(i) == Find(j)) {
				cout << "WARNING";
				return 0;
			}
			Union(i, j);
		}
	}
	cout << "STABLE";
}