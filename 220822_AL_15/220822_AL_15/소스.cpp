#include <iostream>
#include <vector>

using namespace std;

char parents[200];
int GroupCnt[200];

int Find(int now) {
	if (parents[now] == now) return now;
	return parents[now] = Find(parents[now]);
}

void Union(int a, int b) {
	int pA = Find(a);
	int pB = Find(b);

	if (pA == pB) return;

	parents[pB] = pA;

	GroupCnt[pA] += GroupCnt[pB];
	GroupCnt[pB] = 0;
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	for (int i = 0; i < 200; i++){
		parents[i] = i;
		GroupCnt[i] = 1;
	}


	int num;
	cin >> num;
	vector<char> v(num);

	Union('A', 'B');
	Union('A', 'C');

	Union('E', 'F');
	Union('E', 'D');

	Union('H', 'G');

	Union('I', 'J');

	for (int i = 0; i < num; i++) {
		char a, b;
		cin >> a >> b;
		Union(a, b);
	}
	char temp = 'a';
	int cnt = 0;
	for (char a = 'A'; a <= 'J'; a++) {
		if (temp != Find(a)) {
			cnt++;
			temp = Find(a);
		}
	}
	cout << cnt;
}