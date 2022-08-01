#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
9 10
1 2
1 7
2 3
3 4
3 8
4 5
4 6
8 9
7 3
8 6
*/
/*
1. �׷��� ����
  - �� node���� ����
2. queue ����
3. ���۳�� ����
---------------�غ�Ϸ�

4. queue���� node(now)�� �ϳ� ����
	�� ���� ���ѳ��� ������ node
5. now���� �� �� �ִ� node(next)�� ã��
6. next���� queue�� �߰�

7. 4~6�ܰ� �ݺ�
  (�� �̻� ������ �ȵɶ�����
   == queue�� �����������)

// �������
1. ���� ���� �� ���� �Ǵ°�? (ã�Ҵ� ���� �� ã�� �Ǵ°�????) <- used�� �ذ�


*/
int main()
{
	int cntnode, cntedge;
	cin >> cntnode >> cntedge;
	int arr[10][10] = { 0, }; // ���� ���
	for (int i = 0; i < cntedge; i++)
	{
	    int from, to;
	    cin >> from >> to;
	    arr[from][to] = 1;
	}//1. �׷��� ����

	// 2. queue����
	queue<int> q;
	int used[10] = { 0, }; // index : node��ȣ, value : �ش� ���� ã�Ҵ°�?
	int cnt[10] = {0, }; // index : node��ȣ, value : �ִ��� ���� ���� ����� ���� '����� ��'

	// 3. ������ ����
	used[1] = 1; // �������� ���� ã������ ���� ���
	cnt[1] = 1; // �������� 1���� ����� Ȯ���̴� ���� ���
	q.push(1);

	// 7. 4~6�ܰ� �ݺ�
	while(!q.empty()){
	    // 4. now������
	    int now = q.front();
	    q.pop();

	    // -----------
	    // ������ ����� �� �������� ó��
	    cout << now << " : " << cnt[now] << "\n";
	    // -----------

	    // 5. now -> nextã��
	    for (int next = 1; next <= cntnode; next++)
	    {
	        // -------------
	        // now -> next�� �� �� �ִ��� ������ ����(���� ����)
	        if (arr[now][next] == 0) continue;
	        // -------------

	        // ----------------
	        // ã���� ���� �������� ó�� ( �ϴ� ã������ ��� )
	        cnt[next] += cnt[now]; // now->next�� ���� ����� ã�Ҵ�. now���� ���� ����� ����ŭ next�� ���� ����� �߰������� ã�Ҵ�.
	        // �߰� �� �� �ִ°�?(option)
	        // 6. next�� queue�� �߰�
	        if (used[next] != 0) continue; // ã�Ҵ� ����� ������ ����
	        used[next] = 1; // next�� ã�Ҵٶ�� ���
	        q.push(next);
	        // ---------------
	    }
	}
