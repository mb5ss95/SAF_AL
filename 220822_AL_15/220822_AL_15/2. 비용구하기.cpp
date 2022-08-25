#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Edge {
	int from, to, cost;
};
bool cmp(Edge A, Edge B) {
	if (A.cost < B.cost) return true;
	if (A.cost > B.cost) return false;
	return false;
} // 비용이 작은 것부터 나오도록 정렬

vector<Edge> edge;

int parents[10];

int Find(int now) {
	if (now == parents[now])
		return now;
	return parents[now] = Find(parents[now]);
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	parents[pB] = pA;
}

int main()
{

	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;

	for (int i = 1; i <= nodeCnt; i++)
		parents[i] = i; // 각각의 node는 각각 대표이다.

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		edge.push_back({ from, to, cost });
	}

	// 정렬
	sort(edge.begin(), edge.end(), cmp);

	// cost가 작은 edge부터 연결
	int sum = 0; // 최대한 적은 비용으로 모든 node를 연결했을 때의 비용
	for (int i = 0; i < edge.size(); i++)
	{
		// i 번째 edge가 연결하는 두 node(서로 연결, Union)
		int from = edge[i].from;
		int to = edge[i].to;

		// from과 to가 '이미' 같은 그룹
		if (Find(from) == Find(to)) continue; // from과 to가 서로 같은 그룹이였으면 '무시'

		Union(from, to); // from과 to를 하나의 그룹으로 만듦
		sum += edge[i].cost; // 이번에 사용한 edge의 비용을 누적
	}
	cout << sum;


	return 0;
}