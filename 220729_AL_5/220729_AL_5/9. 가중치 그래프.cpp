#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
	int loc;
	int price;
};

vector<vector<Node>> alist(5);
int used[5];

void run(int now, int sum) {

	if (now == 4) {
		cout << sum << " ";
		return;
	}

	for (int i = 0; i < alist[now].size(); i++) {
		Node next = alist[now][i];

		//next.loc : ���� ���� ��ġ
		//next.price : ���� ������ ����

		if (used[next.loc] == 1) continue;
		used[next.loc] = 1;
		run(next.loc, sum + next.price);
		used[next.loc] = 0;
	}

}

int main()
{
	alist[1] = { { 2, 7} };
	alist[2] = { {4, 10}, {3, 5} };
	alist[3] = { {4, 2} };

	used[1] = 1;
	run(1, 0);

	return 0;
}