#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);

	int arr[10][10] = { 0 };
	int N, M, K;

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int from, to, k;
		cin >> from >> to >> k;
		arr[from][to] = k;
	}

	queue<int> q; 
	int dist[10] = { 0, }; 

	dist[0] = 0;
	q.push(0); 

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int next = 0; next < N; next++)
		{
			if (arr[now][next] == 0) continue;
			if (K < dist[now]) continue;

			dist[next] = dist[now] + arr[now][next];
			q.push(next);
		}
	}

	return 0;
}