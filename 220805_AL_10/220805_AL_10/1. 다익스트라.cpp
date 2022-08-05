#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct node {
	int to;
	int cost;
};

bool operator<(node t, node v) {

	return t.cost < v.cost;
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);

	vector<node> edge[10];
	vector<int> dist;

	int n, m;
	cin >> n >> m;
	
	// 모든 dist의 기록을 무한으로 바꿈
	for (int i = 0; i < 10; i++) {
		dist.push_back(21e8);
	}

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge[from].push_back({ to, cost });
	}
	priority_queue<node> pq;

	// 초기 값 세팅(출발할 지점)
	pq.push({ 1, 0 });
	dist[1] = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		for (int i = 1; i <= edge[now.to].size(); i++) {
			node next = edge[now.to][i];

			// 다음 노드까지의 새로운 total 값
			int next_total = now.cost + next.cost;

			if (next_total > dist[next.to]) continue; 

			// 새로운 total 값이 기존 total 값보다 작으면 갱신
			// 기존 total 값은 dist에 기록되어 있음
			dist[next.to] = next_total;
			pq.push({ next.to, next_total });
		}
	}

	for (int i = 0; i < dist.size(); i++) {
		cout << dist[i] << " ";
	}
}