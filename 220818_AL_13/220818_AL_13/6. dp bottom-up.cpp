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
// dp, bottom-up 버전
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

int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	int R, C;
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> MAP[i][j];
			DP[i][j] = -2134567890;
			//-2147483648
		}
	}

	// 초기값 : 계산했던 좌표인지?(계산상 나올 수 없는 값) => 0을 초기값으로 설정 -> 계산해서 0점인지 아니면 계산한게 아닌지
	//     추후 사용시 DP값을 봤을 때, 계산상 나올 수 없는 값을 갖고 있으면 아직 계산하지 않은 경우(한 번 계산해봄)
	//                                 계산상 나올 수 있는 다른 값을 갖고 있으면 계산한적 있으니, 다시 계산할 필요 없이 그냥 가져다 쓰는 형태

	for (int row = 1; row <= R; row++)
	{
		for (int col = 1; col <= C && col <= row; col++)
		{
			if (MAP[row][col] == 0) // 벽이 있는 좌표
				continue;
			if (row == 1) { // 맨 위 좌표는 '이전'좌표가 없으므로 직접 값 세팅
				DP[row][col] = MAP[row][col];
				continue;
			}
			// DP[row][col]; // <- row,col으로 올 수 있는 방법 : 3가지(3가지 방향에서)
			int maxPrevValue = -2134567890; // row,col로 올 수 있는 방법들에서 얻을 수 있는 '최대 점수'
			int dr[] = { -1,-1,-1 };
			int dc[] = { -1, 0, 1 };
			for (int i = 0; i < 3; i++)
			{
				int pr = row + dr[i];
				int pc = col + dc[i];
				if (pr <= 0 || pc <= 0 || pr > R || pc > C) continue; // 맵의 범위를 벗어나면 무시
				if (DP[pr][pc] == -2134567890) // 계산한적 없는 좌표다 => 갈 수 없기에 무시된 좌표 => now로 올 수 없는 경우
					continue;
				// pr,pc : row,col으로 올 수 있는 '이전'좌표
				maxPrevValue = max(maxPrevValue, DP[pr][pc]);  // << ----특정 data를 가져와서 사용 : pr,pc까지 오는데 '몇 점'이였는가?
			}
			if (maxPrevValue == -2134567890) continue; // now로 올 수 있는 '이전'좌표가 없었다면 무시
			int maxNowValue = maxPrevValue + MAP[row][col]; // row,col 이전까지의 최대 점수 + row,col점수 = row,col까지의 최대 점수
			DP[row][col] = maxNowValue;
		}
	}

	int ans = -2134567890;
	for (int col = 1; col <= C; col++)
		ans = max(ans, DP[R][col]);
	cout << ans;



	return 0;
}