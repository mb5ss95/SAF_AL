#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string nodes[] = { "", "BTS", "KFC", "moms", "MC", "BBQ" };
	vector<vector<int>> edges = {
		{},
		{2,5},
		{3},
		{4,5},
		{},
		{4}
	};


	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < edges[i].size(); j++) {
			int temp = edges[i][j];
			cout << nodes[temp] << " ";
		}
		cout << "\n";
	}

}