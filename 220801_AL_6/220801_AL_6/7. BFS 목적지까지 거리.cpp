#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
9
1 2 5
1 7 10
2 3 1
3 4 2
3 8 3
4 5 5
4 6 7
8 9 4

	*/


int main(){
	int cntNode;
	cin >> cntNode;
	int arr[10][10] = { 0, }; // ���� ���
	for (int i = 0; i < cntNode - 1; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from][to] = cost;
	} // 1. �׷��� ����

	// 2. Queue ����
	queue<int> q; // queue�� �ִ� ���� : node����
	int dist[10] = { 0, }; // index : ��� ��ȣ, value : �ش� node������ �Ÿ�

	// 3. ���۳�� ����
	dist[1] = 0;
	q.push(1); // 1������ �������̹Ƿ� �־���

	//7. 4~6�ܰ� �ݺ�
	while (!q.empty()) // queue�� ������� �ʾҴ� : ���� ���ѳ��� ������ node�� ���Ҵ�.
	{
		//4. queue���� node(now)�� �ϳ� ����
		int now = q.front(); // now : �̹��� ������ ���ѳ��� node
		q.pop();

		cout << now << ":" << dist[now] << "\n";

		// 5. now���� �� �� �ִ� node(next)�� ã��
		for (int next = 1; next <= 9; next++)
		{
			if (arr[now][next] == 0) continue; // now->next�� ���� ���ϸ� ����

			// now�� next�� ������ų �� �ִ�.
			// -------- ���ο� next��� ���� ã�Ҵ�.

			// 6. next���� queue�� �߰�
			dist[next] = dist[now] + arr[now][next];
			q.push(next);
		}
	}

	// ����� �� ó�� : now������ ��� �� �� ���� ��
	// ã���� �� ó�� : now,next�� �ΰ����� ���� Ȯ���Ҷ�
	// next������ �Ÿ� = now������ �Ÿ� + (now->next)�� �Ÿ�    <= (ó��, ���) now,next


	return 0;
}