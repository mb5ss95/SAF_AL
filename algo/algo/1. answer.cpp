#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int rowSize, colSize;
int MAP[10][10] = { 0, };
vector<Node> blank;
vector<Node> virus;
//queue<Node> virus;
// 1. bfs, 2. dfs
//int bfs()
//{
//    // 1. �׷��� ���� <- ������� ó��
//    int visited[10][10] = {0, };
//    // 2. queue ����
//    // 3. ������ ���� <- ��� ���̷���
//    queue<Node> q = virus;
//    
//    int blankCnt = 0; // ��ĭ�� ����
//
//    // 7. 4~6�ܰ� �ݺ�
//    while (!q.empty())
//    {
//        // 4. now
//        Node now = q.front(); q.pop();
//
//        // 5. now->next
//        int dr[] = { -1,1,0,0 };
//        int dc[] = { 0,0,-1,1 };
//        for (int i = 0; i < 4; i++)
//        {
//            int nr = now.row + dr[i];
//            int nc = now.col + dc[i];
//            if (visited[nr][nc]) continue; // ã�Ҷ� ����� ������ ����
//            if (MAP[nr][nc] != 0) continue; // ��ĭ�� �ƴϸ� ���� ����
//            // 6. next�� queue�� �߰�
//            visited[nr][nc] = 1;
//            blankCnt++; // ���̷����� ���ĵ� ��ĭ�� ����
//            q.push({ nr, nc });
//        }
//    }
//    return blank.size() - 3 - blankCnt; // ��ü ��ĭ ���� - ������ ���� ���� - ������ ��ĭ �� = ���� ������ ��
//}

int visited[10][10] = { 0, };
int blankCnt = 0;

void dfs(Node now)
{
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	for (int i = 0; i < 4; i++)
	{
		int nr = now.row + dr[i];
		int nc = now.col + dc[i];
		if (MAP[nr][nc] != 0) continue; // ��ĭ�� �ƴϸ� ���� ����
		if (visited[nr][nc]) continue; // ã�Ҷ� ����� ������ ����
		visited[nr][nc] = 1;
		blankCnt++;
		dfs({ nr, nc });
	}
}




void SetupWall(Node coord, int stat)
{
	// ���� ����ų� ���� ���ִ� ���
	MAP[coord.row][coord.col] = stat; // stat : 1 �������, stat : 0 ���㹰��
}

int solution()
{
	int maxValue = 0;
	// 1. 3���� ��ĭ�� �̱�
	for (int i = 0; i < blank.size(); i++)
		for (int j = i + 1; j < blank.size(); j++)
			for (int k = j + 1; k < blank.size(); k++)
			{
				blank[i], blank[j], blank[k];
				// ���� ��ĭ�� �� �����
				SetupWall(blank[i], 1);
				SetupWall(blank[j], 1);
				SetupWall(blank[k], 1);
				// *���̷����� ���� <- �������� ���� ��ĭ ����*

				for (int row = 0; row < 10; row++)
					for (int col = 0; col < 10; col++)
						visited[row][col] = 0;
				blankCnt = 0;

				for (int l = 0; l < virus.size(); l++)
					dfs(virus[l]);
				if (blankCnt == 35) int de = 1;
				maxValue = max(maxValue, (int)blank.size() - 3 - blankCnt);

				//maxValue = max(maxValue, bfs());
				// ���� ���� �κ��� ����
				SetupWall(blank[i], 0);
				SetupWall(blank[j], 0);
				SetupWall(blank[k], 0);
			}
	return maxValue;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> rowSize >> colSize;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			MAP[i][j] = 1;
	for (int row = 1; row <= rowSize; row++)
		for (int col = 1; col <= colSize; col++)
		{
			cin >> MAP[row][col];
			if (MAP[row][col] == 0)
				blank.push_back({ row, col });
			else if (MAP[row][col] == 2)
			{
				virus.push_back({ row, col });
				//virus.push({row, col});
			}
		}
	// ��� ��ĭ�� ã�ƾ���
	cout << solution();
}