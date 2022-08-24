#include <iostream>

using namespace std;

int parents[100];
int GroupCount[100];
int GroupCnt = 0;

int Find(int now) {
	if (parents[now] == now) return now;
	int ret = Find(parents[now]);

	parents[now] = ret; // 경로압축
	return ret;

}

void Union(int a, int b) {
	if (GroupCount[a] == 0) {
		GroupCount[a] = 1;
		GroupCnt++;
	}
	if (GroupCount[b] == 0) {
		GroupCount[b] = 1;
		GroupCnt++;
	}


	int pA = Find(a);
	int pB = Find(b);

	if (pA == pB) return;

	parents[pB] = pA;
	GroupCnt--;
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;

	for (int i = 0; i < 100; i++) parents[i] = i;

	for (int i = 0; i < num; i++) {
		char a, b;
		cin >> a >> b;
		Union(a - 'A', b - 'A');
	}
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		sum = sum + GroupCount[i];
	}
	cout << GroupCnt << "\n" << 26 - sum;
	int h = 0;
}