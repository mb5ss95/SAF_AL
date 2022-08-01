#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
1. �׷��� ����
  - �� node���� ����
2. Queue ����
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
2. 2���� ��(���� ����) : ���� ����� ��ǥ�� ���Ǵ°�?

*/

/*
Flood Fill
2���� �ʿ��� Ž���ϸ� �������� ����Ͽ� ä�������� ���
�����¿�� �̵��� �����ϴ�.

ù �ٿ� ���� ũ��(N)
�̾��� N���� �ٿ� ���� N���� ���ڵ��� �־�����, �ʿ� ���� ������ �־���
5
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0
*/

struct Node {
	int row;
	int col;
};

int main()
{
	int size;
	cin >> size;
	int MAP[10][10];
	for (int row = 0; row < size; row++)
		for (int col = 0; col < size; col++)
			cin >> MAP[row][col];
	//  BFS 1�ܰ� : �׷��� ���� <- �� node���� ����(� node���� � node�� �� �� �ִ°�?)

	/*
	row,col <- ����ؼ� ������ ��
	now��� row,col�� �ش��ϴ� �� -> next��� ������ �� '���'
	*/

	// 2. Queue�� ����
	queue<Node> q; // q�� ���� ���� : node����(� node�ΰ�? ������ ���ѳ��� node��ȣ)
				   //                 row, col -> 2���� ���� -> node 1��
	int used[10][10] = { 0, };
	// used[row][col] = row,col�� ã�� �� �ִ°�?
	//        upgrade : row,col�� �� ���� ���� ����� �� �� �մ°�?

	// 3. ������ ����
	used[0][0] = 1; // 0,0�� ã�Ҵ�. ���
	q.push({ 0, 0 }); // row = 0, col = 0���� ����

	// 7. 4 ~ 6 �ܰ� �ݺ�
	while (!q.empty()) {
		// 4. now������
		Node now = q.front();
		q.pop();
		// 5. **** now->nextã�� (�����¿�) -> ����迭
		int dr[] = { 0,0,1,-1 };
		int dc[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++)
		{
			int nextRow = now.row + dr[i];
			int nextCol = now.col + dc[i];
			// nextRow, nextCol : now ���� �� �� �ִ� ���� ��(next)
			if (nextRow < 0 || nextCol < 0 || nextCol >= size || nextRow >= size)
				continue; // ���� ����� ��ǥ�� ���Ǹ� ����
			if (used[nextRow][nextCol] != 0) continue; // � ����� �ִ� ��ǥ����(ã�Ҵ� ��ǥ����) ����
			if (MAP[nextRow][nextCol] == 1)continue; // ���̸� ����

			// 6. next�� queue�� �߰�
			used[nextRow][nextCol] = used[now.row][now.col] + 1; // nextRow, nextCol�� ã�Ҵ�. ���
			q.push({ nextRow, nextCol });
		}
	}

	return 0;
}