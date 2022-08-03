#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
	int x;
	char y;
};

bool compare(node n1, node n2) {
	if (n1.y < n2.y) return 1;
	if (n1.y > n2.y) return 0;

	return n1.x > n2.x;
}

int main() {
	vector<node> vec = {
		{8, 'B'},
		{3, 'B'},
		{3, 'A'},
		{9, 'B'},
		{2, 'C'},
		{1, 'D'},
		{1, 'A'},
		{9, 'C'}
	};

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].x << " " << vec[i].y << "\n";
	}
}