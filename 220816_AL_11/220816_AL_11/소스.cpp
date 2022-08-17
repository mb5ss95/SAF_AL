#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
	freopen_s(new FILE*, "sample.txt", "r", stdin);
	vector<int> datas;
	queue<int> q;

	int N, T;
	cin >> N >> T;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		datas.push_back(temp);
		q.push(temp);
	}
	int cnt = 0;
	int pre = -1;
	int s = 0;
	int e = 1;
	int sum = datas[s];
	while (1) {
		if (sum > T) {
			sum = sum - datas[s];
			s++;
		}
		if (e >= N) {
			s++;
			continue;
		}
		if (sum < T) {
			sum = sum + datas[e];
			e++;
		}
		if (sum == T) {
			cnt++;
			sum = sum + datas[e];
			e++;
		}
	}
	cout << cnt;
}