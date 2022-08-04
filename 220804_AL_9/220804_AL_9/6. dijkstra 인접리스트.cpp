#include <iostream>
#include <queue>
#include<vector>
using namespace std;

/*
1. ���� Ȯ������ ���� node�� �� ���� �����(���������κ���) node�� �ϳ� select
2. select�� node�� ������� �� �� �ִ� ��� node�� ���� �Ÿ��� ����
*/
/*
8 <- node����
11<- edge����
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
	vector<Edge> v[10];// ���� ����Ʈ
	for (int i = 0; i < cntEdge; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	} // 1. �׷��� ����

	// �ʿ��� data �غ� : �Ÿ�, Ȯ�� ����
	int dist[10];
	int used[10] = { 0, }; // index : node��ȣ, value : �ش� ���� Ȯ���ߴ°�?
	for (int i = 1; i <= cntNode; i++)
		dist[i] = 2134567890; // dist�� ū������ '�� �� ����'�� ���·� �ʱ�ȭ


	dist[1] = 0; // ������ ����


	for (int times = 1; times < cntNode; times++) {
		// 1. ���� ����� ��(now) �ϳ� ����(Ȯ������ ���� �� �߿���)
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

		// ���� Ȯ��
		used[now] = 1;

		// Ȯ���� now�� ������� next���� ����
		for (int i = 0; i < v[now].size(); i++)
		{
			Edge edge = v[now][i];
			int next = edge.to; // now->next ��� �� ��ȣ
			int edgeDist = edge.cost;// now->next�� ���� ���(�Ÿ�)
			// ������ -> now -> next
			if (dist[now] + edgeDist > dist[next]) continue;
			dist[next] = dist[now] + edgeDist;
		}
	}
	int de = 1;
	return 0;
}