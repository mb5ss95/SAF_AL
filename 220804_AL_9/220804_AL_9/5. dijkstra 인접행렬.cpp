#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// �ִܰŸ� ���ϱ�
// ���� ��� ���
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
	//�ʿ��� ������ ���������κ����� �Ÿ�
	int dist[10];
	for (int i = 0; i < 10; i++) {
		dist[i] = 21e8; // �������� ���� �� ���� ũ���� ��(����� �Ѱ��� �ƴϸ� �츮�� ���� �𸣴���)
	} // dist ù ����
	dist[1] = 0; // ������

	for (int times = 1; times <= n; times++) {
		// 1. Ȯ������ ���� ��� �߿��� ���� �����(��������������) ��带 �ϳ� ����
		int now = -1; // �̹��� Ȯ���� ��(���������� ���� ����� ��)
		int mindist = 21e8; // ���ݱ��� �� (Ȯ������ ���� �Ÿ��� �ִܰŸ�)
		for (int i = 1; i <= n; i++) {
			if (dist[i] < mindist && used[i] == 0) { //Ȯ������ ���� �� �߿��� ���� ª�� �Ÿ�
				mindist = dist[i];
				now = i;
			}
		}

		used[now] = 1; // now�� Ȯ����

		// 2. ������ ���(now)�� ������� �� �� �ִ� ��� ���(next)�� ���� �Ÿ��� ����
		for (int next = 1; next <= n; next++) {
			if (arr[now][next] == 0) continue; // now->next�� �� �� ������ ����
			// �ϴ� next�� now���� ������ �ִ�
			// dist[now] ���������� now������ �Ÿ�
			// arr[now][next] now���� next������ �Ÿ�
			// ���������� now�� ���� next������ �Ÿ� = dist[now] + arr[now][next]

			// now�� ���� ���°� �տ��� ���� �Ÿ����� Ŭ�� ����
			if (dist[now] + arr[now][next] > dist[next]) continue;
			dist[next] = dist[now] + arr[now][next];

		}
	}
	for (int i = 0; i < 10; i++) {
		cout << i << " : " << dist[i] << "\n";
	}
}