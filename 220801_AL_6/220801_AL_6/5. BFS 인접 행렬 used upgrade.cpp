#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
9 9
1 2
1 7
2 3
7 3
3 4
3 8
4 5
4 6
8 9
*/

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);

	int arr[10][10] = { 0 };
	int cntNode, cntEdge;

	cin >> cntNode >> cntEdge;

	for (int i = 1; i < 10; i++) {
		int from, to;

		cin >> from >> to;

		arr[from][to] = 1;
	}

	queue<int> q;
	int used[10] = { 0 };
	// index -> node 번호
	// value -> 감염 됐는가? 감염이 되는 시점은 q에 넣을때 됨

	q.push(1);
	used[1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int next = 1; next <= cntNode; next++) {

			if (arr[now][next] == 0) continue;
			if (used[next] >= 1) continue;

			used[next] = used[now] + 1;
			q.push(next);
		}
	}
}