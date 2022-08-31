#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	freopen_s(new FILE*, "sample.txt", "r", stdin);

	int N;
	cin >> N;

	unordered_map<string, vector<int>> um;

	for (int i = 0; i < N; i++) {
		string name;
		int temp;
		cin >> name >> temp;
		if (um.count(name) == 0) {
			um[name].push_back(1);
			um[name].push_back(temp);
		}
		else {
			um[name][0] = um[name][0] + 1;
			um[name][1] = um[name][1] + temp;
		}
	}

	string coco, cocof;
	cin >> coco >> cocof;
	
	cout << um[coco][0] << " " << um[coco][1] << "\n";
	cout << um[cocof][0] << " " << um[cocof][1] << "\n";
	if (um[coco][1] > um[cocof][1]) cout << coco;
	else cout << cocof;

	return 0;
}