#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// 최단거리 구하기
// 인접 행렬 방식
/*
8 11
1 2 10
1 5 1
2 3 5
3 4 6
3 5 2
3 6 4
3 7 8
4 8 11
5 6 7
6 7 9
7 8 3
*/

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);

	int arr[10][10] = { 0 };
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from][to] = cost;
		arr[to][from] = cost;
	}
	int used[10] = { 0};
	//필요한 데잍터 시작점으로부터의 거리
	int dist[10];
	for (int i = 0; i < 10; i++) {
		dist[i] = 21e8; // 계산상으로 나올 수 없는 크기의 값(계산을 한건지 아니면 우리가 아직 모르는지)
	} // dist 첫 세팅
	dist[1] = 0; // 시작점

	for (int times = 1; times <= n; times++) {
		// 1. 확정하지 않은 노드 중에서 가장 가까운(시작점에서부터) 노드를 하나 선택
		int now = -1; // 이번에 확정하 점(시작점부터 가장 가까운 점)
		int mindist = 21e8; // 지금까지 본 (확정되지 않은 거리중 최단거리)
		for (int i = 1; i <= n; i++) {
			if (dist[i] < mindist && used[i] == 0) { //확정하지 않은 점 중에서 가장 짧은 거리
				mindist = dist[i];
				now = i;
			}
		}

		used[now] = 1; // now는 확정됨

		// 2. 선택한 노드(now)를 기반으로 갈 수 있는 모든 노드(next)에 대한 거리를 갱신
		for (int next = 1; next <= n; next++) {
			if (arr[now][next] == 0) continue; // now->next로 갈 수 없으면 무시
			// 일단 next는 now에서 갈수는 있다
			// dist[now] 시작점에서 now까지의 거리
			// arr[now][next] now에서 next까지의 거리
			// 시작점에서 now를 거쳐 next까지의 거리 = dist[now] + arr[now][next]

			// now를 거쳐 가는게 앞에서 구한 거리보다 클때 무시
			if (dist[now] + arr[now][next] > dist[next]) continue;
			dist[next] = dist[now] + arr[now][next];

		}
	}
	for (int i = 0; i < 10; i++) {
		cout << i << " : " << dist[i] << "\n";
	}
}