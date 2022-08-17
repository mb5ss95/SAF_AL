#include <iostream>
#include <vector>

using namespace std;

struct node {
	int arr[10] = { 0 };
};

int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int startY, startX, endY, endX;
	int N, temp;
	cin >> N;

	vector<vector<node>> map(N + 1, vector<node>(N + 1));
	vector<vector<node>> smap(N + 1, vector<node>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			map[i][j].arr[temp]++;
		}
	}
	int idx;
	for (int i = 1; i <= N; i++) { 
		int brr[10] = { 0 };
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < 10; k++) {
				brr[k] = brr[k] + map[i][j].arr[k] + smap[i - 1][j].arr[k] - smap[i - 1][j - 1].arr[k];
				smap[i][j].arr[k] = brr[k];
				//cout << i << "," << j << "," << k << "," << brr[k] << "\n";
			}
		}
	}

	cin >> temp;
	int max = -21e8;
	int idxx;
	for (int i = 0; i < temp; i++) {
		cin >> startY >> startX >> endY >> endX;
		startX++;
		startY++;
		endX++;
		endY++;
		int brr[10] = { 0 };
		for (int k = 0; k < 10; k++) {
			brr[k] = smap[endY][endX].arr[k] - smap[startY - 1][endX].arr[k] - smap[endY][startX - 1].arr[k] + smap[startY - 1][startX - 1].arr[k];
			if (brr[k] > max) {
				max = brr[k];
				idxx = k;
			}
		}
		cout << idxx << "\n";
	}
}