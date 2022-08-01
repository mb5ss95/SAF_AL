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

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);

	int arr[10][10] = {0};
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
	}

	//2. q ����
	queue<int> q;

	//3. ���� ��� ����
	q.push(1);

	//4. 4~6�ܰ� �ݺ�
	while (!q.empty()) {
		//4. q���� node(now)�� ����
		int now = q.front();
		q.pop();

		cout << now << " ";

		//5. now���� �� �� �ִ� node(next) ã��
		for (int next = 1; next <= 9; next++) {
			if (arr[now][next] == 0) continue;

			//6. next���� q�� �߰�
			q.push(next);
		}
	}

	return 0;
}