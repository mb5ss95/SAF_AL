#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	//freopen_s(new FILE*, "sample.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num;
	cin >> num;
	vector<int> v(num + 100);
	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		v[i] = temp;
	}
	int result = -2392323;
	int mIdx;
	for (int i = 0; i < num; i++) {
		if (v[i] > v[i + 1]) continue;
		int rest = v[i + 1] - v[i];
		if (result < rest) {
			result = rest;
			mIdx = i;
		}
	}
	cout << mIdx << " " << mIdx + 1;

}