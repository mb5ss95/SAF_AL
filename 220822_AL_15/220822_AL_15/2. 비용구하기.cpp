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
} // ����� ���� �ͺ��� �������� ����

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
		parents[i] = i; // ������ node�� ���� ��ǥ�̴�.

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		edge.push_back({ from, to, cost });
	}

	// ����
	sort(edge.begin(), edge.end(), cmp);

	// cost�� ���� edge���� ����
	int sum = 0; // �ִ��� ���� ������� ��� node�� �������� ���� ���
	for (int i = 0; i < edge.size(); i++)
	{
		// i ��° edge�� �����ϴ� �� node(���� ����, Union)
		int from = edge[i].from;
		int to = edge[i].to;

		// from�� to�� '�̹�' ���� �׷�
		if (Find(from) == Find(to)) continue; // from�� to�� ���� ���� �׷��̿����� '����'

		Union(from, to); // from�� to�� �ϳ��� �׷����� ����
		sum += edge[i].cost; // �̹��� ����� edge�� ����� ����
	}
	cout << sum;


	return 0;
}