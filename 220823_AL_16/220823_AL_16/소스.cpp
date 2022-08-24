#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct node {
	int parents;
	int y, x;
	int r;
	int cnt;
};

bool compare(node a, node b) {
	return a.parents < b.parents;
}
bool compare2(node a, node b) {
	if (a.y < b.y) return 1;
	if (a.y > b.y) return 0;

	return a.x < b.x;
}
vector<node> v;

int Find(int now) {
	if (v[now].parents == now) return now;
	return v[now].parents = Find(v[now].parents);
}

void Union(int a, int b) {
	int aP = Find(a);
	int bP = Find(b);

	if (aP == bP) return;

	v[bP].parents = aP;
	v[aP].cnt = v[aP].cnt + v[bP].cnt;
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int num;
		cin >> num;

		vector<node> temp;

		for (int i = 0; i < num; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			temp.push_back({ i, y, x, r, 1});
		}

		v = temp;
		sort(v.begin(), v.end(), compare2);
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (i == j) continue;
				int ny = (v[i].y - v[j].y) * (v[i].y - v[j].y);
				int nx = (v[i].x - v[j].x) * (v[i].x - v[j].x);
				int rs = (v[i].r * v[i].r) + (v[j].r * v[j].r) + (v[i].r + v[j].r) + (v[i].r + v[j].r);
				if (rs < (ny + nx)) continue;
				if (Find(i) == Find(j)) continue;
				Union(i, j);
				Find(j);
			}
		}
		sort(v.begin(), v.end(), compare);
		int sum = 0;
		int tempN = -13123;
		for (node n : v) {
			if (tempN != n.parents) {
				tempN = n.parents;
				sum++;
			}
		}

		cout << sum << "\n";
	}
}