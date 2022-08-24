#include <iostream>

using namespace std;

int PARENTS[100];

int Find(int now) {
	if (PARENTS[now] == now) return now;
	int ret = Find(PARENTS[now]);
	PARENTS[now] = ret;

	return ret;
}

int Union(int a, int b) {
	int pA = Find(a);
	int pB = Find(b);

	if (pA == pB) return 0;

	PARENTS[pB] = pA;
	return 1;
}


int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) PARENTS[i] = i;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < i+1; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				if (Union(i, j) == 0) {
					cout << "WARNING";
					return 0;
				}
			}
		}
	}
	cout << "STABLE";
	int h = 0;
}