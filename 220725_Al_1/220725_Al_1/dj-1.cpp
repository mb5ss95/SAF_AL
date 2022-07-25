#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	int MAP[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	    {0, 2, 0, 0, 0, 0, 0, 0, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	    {0, 0, 0, 0, 0, 0, 0, 100, 0, 0},
	    {0, 0, 0, 0, 0, 10, 0, 0, 0, 0},
	    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
	    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	    {1, 0, 0, 20, 0, 0, 0, 1, 0, 0},
	    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	int row, col;

	cin >> row >> col;

	MAP[row+0][col+0]; // 0번째 자기자신
	MAP[row+0][col-1]; // 1번째 왼쪽
	MAP[row+0][col+1]; // 2번째 오른쪽
	MAP[row-1][col+0]; // 3번째 위
	MAP[row+1][col+0]; // 4번째 아래

	int dr[] = { 0,0,0,-1,1 };
	int dc[] = { 0,-1,1,0,0 };

	for (int i = 0; i < 5; i++) {
		// d를 기반으로 다음 좌표 계산
		int nr = row + dr[i]; // row쪽 방향 배열
		int nc = col + dc[i]; // col쪽 방향 배열
		
		// 방향을 벗어나면 무시
		if (nr < 0 || nc < 0) continue;
		if (nr > 9 || nc > 9) continue;

		//
		if (MAP[nr][nc] != 0) {
			for (int i = 0; i < MAP[nr][nc]; i++) cout << "BOOm!!";
		}
	}
	return 0;
}