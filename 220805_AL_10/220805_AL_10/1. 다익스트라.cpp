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
	
	// ��� dist�� ����� �������� �ٲ�
	for (int i = 0; i < 10; i++) {
		dist.push_back(21e8);
	}

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge[from].push_back({ to, cost });
	}
	priority_queue<node> pq;

	// �ʱ� �� ����(����� ����)
	pq.push({ 1, 0 });
	dist[1] = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		for (int i = 1; i <= edge[now.to].size(); i++) {
			node next = edge[now.to][i];

			// ���� �������� ���ο� total ��
			int next_total = now.cost + next.cost;

			if (next_total > dist[next.to]) continue; 

			// ���ο� total ���� ���� total ������ ������ ����
			// ���� total ���� dist�� ��ϵǾ� ����
			dist[next.to] = next_total;
			pq.push({ next.to, next_total });
		}
	}

	for (int i = 0; i < dist.size(); i++) {
		cout << dist[i] << " ";
	}
}