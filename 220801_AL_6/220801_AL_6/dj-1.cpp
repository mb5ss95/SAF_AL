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