#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
1. 그래프 구성
  - 각 node간의 관계
2. Queue 생성
3. 시작노드 세팅
---------------준비완료

4. queue에서 node(now)를 하나 꺼냄
	ㄴ 감염 시켜나갈 예정인 node
5. now에서 갈 수 있는 node(next)들 찾기
6. next들을 queue에 추가

7. 4~6단계 반복
  (더 이상 감염이 안될때까지
   == queue가 비워질때까지)

// 고려사항
1. 갔던 점을 또 가게 되는가? (찾았던 점을 또 찾게 되는가????) <- used로 해결
2. 2차원 맵(주의 사항) : 맵을 벗어나는 좌표가 계산되는가?

*/

/*
Flood Fill
2차원 맵에서 탐색하며 정보들을 계산하여 채워나가는 방식
상하좌우로 이동이 가능하다.

첫 줄에 맵의 크기(N)
이어진 N개의 줄에 걸쳐 N개의 숫자들이 주어지며, 맵에 대한 정보가 주어짐
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
	//  BFS 1단계 : 그래프 구성 <- 각 node간의 관계(어떤 node에서 어떤 node로 갈 수 있는가?)

	/*
	row,col <- 계산해서 인접한 점
	now라는 row,col에 해당하는 점 -> next라는 인접한 점 '계산'
	*/

	// 2. Queue를 생성
	queue<Node> q; // q에 넣은 정보 : node정보(어떤 node인가? 전염을 시켜나갈 node번호)
				   //                 row, col -> 2개의 정보 -> node 1개
	int used[10][10] = { 0, };
	// used[row][col] = row,col을 찾은 적 있는가?
	//        upgrade : row,col은 몇 개의 점을 들려서 갈 수 잇는가?

	// 3. 시작점 세팅
	used[0][0] = 1; // 0,0은 찾았다. 기록
	q.push({ 0, 0 }); // row = 0, col = 0에서 시작

	// 7. 4 ~ 6 단계 반복
	while (!q.empty()) {
		// 4. now꺼내기
		Node now = q.front();
		q.pop();
		// 5. **** now->next찾기 (상하좌우) -> 방향배열
		int dr[] = { 0,0,1,-1 };
		int dc[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++)
		{
			int nextRow = now.row + dr[i];
			int nextCol = now.col + dc[i];
			// nextRow, nextCol : now 에서 갈 수 있는 다음 점(next)
			if (nextRow < 0 || nextCol < 0 || nextCol >= size || nextRow >= size)
				continue; // 맵을 벗어나는 좌표가 계산되면 무시
			if (used[nextRow][nextCol] != 0) continue; // 어떤 기록이 있는 좌표더라(찾았던 좌표더라) 무시
			if (MAP[nextRow][nextCol] == 1)continue; // 벽이면 무시

			// 6. next를 queue에 추가
			used[nextRow][nextCol] = used[now.row][now.col] + 1; // nextRow, nextCol을 찾았다. 기록
			q.push({ nextRow, nextCol });
		}
	}

	return 0;
}