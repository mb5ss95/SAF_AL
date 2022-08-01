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
	int arr[10][10] = { 0, }; // 인접 행렬
	for (int i = 0; i < cntNode - 1; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from][to] = cost;
	} // 1. 그래프 구성

	// 2. Queue 생성
	queue<int> q; // queue에 넣는 정보 : node정보
	int dist[10] = { 0, }; // index : 노드 번호, value : 해당 node까지의 거리

	// 3. 시작노드 세팅
	dist[1] = 0;
	q.push(1); // 1번점이 시작점이므로 넣어줌

	//7. 4~6단계 반복
	while (!q.empty()) // queue가 비워지지 않았다 : 감염 시켜나갈 예정인 node가 남았다.
	{
		//4. queue에서 node(now)를 하나 꺼냄
		int now = q.front(); // now : 이번에 감염을 시켜나갈 node
		q.pop();

		cout << now << ":" << dist[now] << "\n";

		// 5. now에서 갈 수 있는 node(next)들 찾기
		for (int next = 1; next <= 9; next++)
		{
			if (arr[now][next] == 0) continue; // now->next로 가지 못하면 무시

			// now가 next를 감염시킬 수 있다.
			// -------- 새로운 next라는 점을 찾았다.

			// 6. next들을 queue에 추가
			dist[next] = dist[now] + arr[now][next];
			q.push(next);
		}
	}

	// 들렸을 때 처리 : now만보고 계산 할 수 있을 때
	// 찾았을 때 처리 : now,next의 두가지를 같이 확인할때
	// next까지의 거리 = now까지의 거리 + (now->next)의 거리    <= (처리, 계산) now,next


	return 0;
}