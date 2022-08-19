#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <Windows.h>

using namespace std;

struct node {
	int y, x;
	int value;
};

void action(vector<vector<node>> v, int N) {
	system("cls");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			if (v[i][j].value == 0) cout << "  ";
			else cout << v[i][j].value << " ";
		}
		cout << "\n";
	}
	Sleep(1000);
}


vector<vector<node>> refresh(vector<vector<node>> v, int N) {
	for (int i = 9; i >= 0; i--) {
		for (int j = N-1; j >= 1; j--) {
			if (v[j][i].value == 0) {
				v[j][i].value = v[j - 1][i].value;
				v[j - 1][i].value = 0;
			}
		}
	}

	return v;
}

vector<vector<node>> bomb(vector<vector<node>> v, node start, int K) {
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0,-1, 1 };

	int len = v.size();
	int val = start.value;
	int cnt = 0;

	queue<node> q;
	queue<node> aq;
	q.push(start);
	
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= len || nx >= 10) continue;
			if (v[ny][nx].value != val) continue;
			v[ny][nx].value = 0;

			aq.push(v[ny][nx]);
			q.push(v[ny][nx]);
			cnt++;
		}
	}
	if (cnt < K) {
		while (!aq.empty()) {
			node target = aq.front();
			aq.pop();
			v[target.y][target.x].value = val;
		}
	}

	return v;
}

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K, temp;
	cin >> N >> K;

	vector<vector<node>> v(N, vector<node>(10));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 10; j++) {
			int temp = str[j]-'0';
			v[i][j] = { i, j, temp };
		}
	}

	for (int j = 0; j < 50; j++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 10; j++) {
				if (v[i][j].value == 0) continue;
				v = bomb(v, v[i][j], K);
				action(v, N);
				v = refresh(v, N);
				action(v, N);
			}
		}
		//v = refresh(v, N);
	}

	
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cout << v[i][j].value;
		}
		cout << "\n";
	}*/
	int h = 98;

}