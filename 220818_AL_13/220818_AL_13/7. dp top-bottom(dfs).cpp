#include <iostream>
#include <vector>

using namespace std;

/*
1. 답(계산 결과)이 바뀔수있는 변인 요인 설정
-> 개구리가 어느 위치에 도착했는가?
2. 변인요인 : 2가지 (row, col)
-> 배열 설정 dp[row][col] = 해당 좌표까지 갔을 때의 최대점수
3. now라는 상황이 있을때, 해당 상황이 발생할 수 있는 경우들
4. 해당 상황에 대한 값을 활용하여 어떻게 계산할지
*/
// dp, top-bottom 버전
/*
7 3 <- row col
1 0 0 <- MAP정보들(0은 벽, 갈 수 없음)
1 2 2
0 3 0
3 -10 -5
15 -10 50
15 -10 10
0 6 4
*/
int MAP[10][10] = { 0, };
int DP[10][10]; // DP[row][col] : row,col'까지'왔을 때의 최대 점수
int R, C;

int max(int a, int b) {
	return a > b ? a : b;
}

vector<pair<int, int>> path;

void dfs(int row, int col) {

	if (row == R) return; // 맨 밑의 줄까지 오면 더 가지 말고 끝내라
	

	int dr[] = { 1, 1, 1 };
	int dc[] = { -1, 0, 1 };
	for (int i = 0; i < 3; i++) {
		int ny = row + dr[i];
		int nx = col + dc[i];
		/*
		1. 경로상 갔던 점을 다시 가는가? <- 무한 반복이 되는가? pass
		2. 맵의 범위를 벗어나는 좌표를 가는가?
		
		*/
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if (MAP[ny][nx] == 0) continue;
		path.push_back({ ny, nx });
		dfs(ny, nx);
		path.pop_back();
	}
}

int main()
{

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> MAP[i][j];
			DP[i][j] = -2134567890;
			//-2147483648
		}
	}
	path.push_back({ 1, 1 });
	dfs(1, 1);
	
	return 0;
}