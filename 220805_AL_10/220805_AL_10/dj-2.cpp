#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
	int to;
	int cost;
};

bool operator<(node a, node b) {
	return a.cost < b.cost;
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	vector<vector<node>> v(1005);
	vector<int> dist;

	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		dist.push_back(21e8);
	}
	int de = 0;

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}

	int from, to;
	cin >> from >> to;

	priority_queue<node> pq;

	pq.push({ from, 0 });
	dist[from] = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost) continue;

		for (int i = 1; i < v[now.to].size(); i++) {
			node next = v[now.to][i];

			int new_total = now.cost + next.cost;
			
			if (new_total > dist[next.to]) continue;

			dist[next.to] = new_total;
			pq.push({ next.to, new_total });
		}
	}
	cout << dist[to];

}