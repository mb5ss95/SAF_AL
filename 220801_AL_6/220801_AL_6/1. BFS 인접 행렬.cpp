#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*
입력이 주어질떄

1. 그래프 구성
- 각 노드간의 관계
2. 큐 생성
3. 시작 노드 세팅
--------------------------준비완료
4. 큐에서 노드(now)를 하나꺼냄
- 감염 시켜나갈 예정인 노드

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

	//2. q 생성
	queue<int> q;

	//3. 시작 노드 세팅
	q.push(1);

	//4. 4~6단계 반복
	while (!q.empty()) {
		//4. q에서 node(now)를 꺼냄
		int now = q.front();
		q.pop();

		cout << now << " ";

		//5. now에서 갈 수 있는 node(next) 찾기
		for (int next = 1; next <= 9; next++) {
			if (arr[now][next] == 0) continue;

			//6. next들을 q에 추가
			q.push(next);
		}
	}

	return 0;
}