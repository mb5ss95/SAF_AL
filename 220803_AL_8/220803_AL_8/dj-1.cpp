#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
	int num;
	int price;
	int level;
};

vector<vector<node>> vec(6);

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		vec[from].push_back({to, cost});
	}

	queue<node> q;
	q.push({ 1, 0 });

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < vec[now.num].size(); i++) {
			node next = vec[now.num][i];
			q.push({ next.num, now.price + next.price, now.level + 1 });

			if (next.num == 5) {
				cout << "µµÂø!! " << now.level << "\n";
				cout << now.price + next.price;
				return 0;
			}

		}
	}
}