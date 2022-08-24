#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	char a, b;
	int val;
};

int parents[1100];
int dat[1100];
int perCnt = 0;

bool compare(node a, node b) {
	return a.val < b.val;
}

int Find(int now) {
	if (parents[now] == now) return now;

	return parents[now] = Find(parents[now]);
}

void Union(int a, int b) {
	int pA = Find(a);
	int pB = Find(b);

	if (pA == pB) return;

	parents[pB] = pA;

	if (dat[a] == 0) perCnt++;
	if (dat[b] == 0) perCnt++;

	dat[a] = 1;
	dat[b] = 1;
}


int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;
	vector<node> v;
	for (int i = 0; i < num; i++) parents[i] = i;
	for (int i = 0; i < num; i++) {
		char a, b;
		int val;
		cin >> a >> b >> val;
		v.push_back({ a - 'A' , b - 'A', val });
	}

	// 1. sort
	sort(v.begin(), v.end(), compare);

	int cnt = 0;
	int result = 0;
	for (int i = 0; i < num; i++) {
		// 같은 그룹인지 검사
		if(Find(v[i].a) == Find(v[i].b)) continue;

		// 같은 그룹이 아니넹,,,친구하자 마!
		Union(v[i].a, v[i].b);
		cnt++;
		result += v[i].val;
		if (cnt == perCnt) break;
	}

	cout << result;
}