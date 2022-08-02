#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <Windows.h>

using namespace std;

struct node {
	int y, x;
	int level;
};

int room[5][5] = { 0 };
int directY[4] = {-1, 0, 1, 0};
int directX[4] = { 0, 1, 0,-1};

void action() {
	system("cls");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << room[i][j]<<" ";
		}
		cout << "\n";
	}
	Sleep(1000);
}

int main() {
	queue<node> q;

	room[2][2] = 1; // 시작 지점
	q.push({ 2, 2, 0 });
	int last = 0;

	while (!q.empty()) {

		node now = q.front();
		q.pop();
		action();

		for (int i = 0; i < 4; i++) {
			int newY = now.y + directY[i];
			int newX = now.x + directX[i];

			if (newY < 0 || newY >= 5 || newX < 0 || newX >= 5) continue;
			if (room[newY][newX] == 1) continue;

			room[newY][newX] = 1;
			q.push({ newY, newX, now.level + 1 });

			last = now.level + 1;
		}
	}

	cout << last;
	
}