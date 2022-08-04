#include <iostream>
#include <queue>
#include<vector>
using namespace std;

/*
1. 아직 확정하지 않은 node들 중 가장 가까운(시작점으로부터) node를 하나 select
2. select한 node를 기반으로 갈 수 있는 모든 node에 대한 거리를 갱신
*/
/*
8 <- node개수
11<- edge개수
1 2 10 <- from, to, cost
1 5 1
2 3 5
3 5 2
3 6 4
3 7 8
3 4 6
4 8 11
5 6 7
6 7 9
7 8 3
*/

struct Edge {
	int to;
	int cost;
};

int main()
{
	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;
	vector<Edge> v[10];// 인접 리스트
	for (int i = 0; i < cntEdge; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	} // 1. 그래프 구성

	// 필요한 data 준비 : 거리, 확정 여부
	int dist[10];
	int used[10] = { 0, }; // index : node번호, value : 해당 점을 확정했는가?
	for (int i = 1; i <= cntNode; i++)
		dist[i] = 2134567890; // dist를 큰값으로 '갈 수 없다'의 형태로 초기화


	dist[1] = 0; // 시작점 세팅


	for (int times = 1; times < cntNode; times++) {
		// 1. 가장 가까운 점(now) 하나 고르기(확정하지 않은 점 중에서)
		int now = -1;
		int mindist = 2134567890;
		for (int i = 1; i <= cntNode; i++)
		{
			if (dist[i] < mindist && used[i] == 0)
			{
				mindist = dist[i];
				now = i;
			}
		}

		// 점을 확정
		used[now] = 1;

		// 확정된 now를 기반으로 next들을 갱신
		for (int i = 0; i < v[now].size(); i++)
		{
			Edge edge = v[now][i];
			int next = edge.to; // now->next 라는 점 번호
			int edgeDist = edge.cost;// now->next로 가는 비용(거리)
			// 시작점 -> now -> next
			if (dist[now] + edgeDist > dist[next]) continue;
			dist[next] = dist[now] + edgeDist;
		}
	}
	int de = 1;
	return 0;
}