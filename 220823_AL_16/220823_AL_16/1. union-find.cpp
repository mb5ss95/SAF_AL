#include <iostream>

using namespace std;

int parents[100];

int Find(int now) {
	if (parents[now] == now) return now;
	int ret = Find(parents[now]);

	parents[now] = ret; // 경로압축
	return ret;

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

	for (int i = 0; i < 100; i++) parents[i] = i;

	Union(5, 6);
	Union(4, 5);
	Union(3, 4);
	Union(2, 3);


	cout<<Find(6);
	int h = 0;
}