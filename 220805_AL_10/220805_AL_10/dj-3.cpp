#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[4][4] = {
	0,1,2,6,
	1,2,5,9,
	2,4,8,11,
	3,7,10,12
};

int dist[4][4] = { 0 };

struct Node {
	int y, x;
	int cost;
};

bool operator<(Node v, Node t) {
	return t.cost < v.cost;
}
priority_queue<Node> q;

int directY[4] = { -1, 1, 0, 0 };
int directX[4] = { 0, 0, -1, 1 };

int main() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			dist[y][x] = 21e8;
		}
	}
	dist[0][0] = 0;

	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		Node now = q.top();
		q.pop();

		//³ë´ä
		if (dist[now.y][now.x] < now.cost) continue;

		for (int t = 0; t < 4; t++) {
			int ny = now.y + directY[t];
			int nx = now.x + directX[t];

			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;

			int nextCost = now.cost + map[ny][nx];

			if (dist[ny][nx] < nextCost) continue;
			dist[ny][nx] = nextCost;
			q.push({ ny, nx, nextCost });
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cout<< dist[y][x] <<" ";
		}
		cout << "\n";
	}

	return 0;
}