#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
�Է��� �־�����

1. �׷��� ����
- �� ��尣�� ����
2. ť ����
3. ���� ��� ����
--------------------------�غ�Ϸ�
4. ť���� ���(now)�� �ϳ�����
- ���� ���ѳ��� ������ ���

*/

struct info {
	int node;
	int gold;
};

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	
	int arr[10][10] = { 0 };
	int num, route, k;
	
	cin >> num >> route >> k;

	for (int i = 0; i < route; i++) {
		int from, to, gold;
		cin >> from >> to >> gold;
		arr[from][to] = 1;
	}

	queue<info> q;
	q.push({ 0, k });

	return 0;
}