#include <iostream>
#include <queue>

using namespace std;

/*
default�� less��, ū �� �켱 => less operator<
				  ���� �� �켱���� ����� ������ -> greater operator>
*/

struct node {
	int row;
	int col;
};

struct cmp { //���ϴ� ����(�켱����)
	bool operator()(node a, node b) {
		//�켱���� �ۼ�
		//b�� �켱������ ������ true
		//a�� �켱������ ������ flase

		//row�� ū�� �켱, row�� ������ col�� ������ �켱
		if (a.row > b.row) return false;
		if (a.row < b.row) return true;

		//row�� ���� ���
		if (a.col < b.col) return 0;
		if (a.col > b.col) return 1;

		//a.row == b.row && a.col == b.col
		return false;
	}
};


void struct_prioriy_queue() {
	priority_queue < node, vector<node>, cmp> pq;
	pq.push({ 1,2 });
	pq.push({ 2,3 });
	pq.push({ 9,2 });
	pq.push({ 5,7 });
	pq.push({ 9,8 });
	pq.push({ 6,2 });
	pq.push({ 6,5 });
	pq.push({ 1,1 });

	while (!pq.empty()) {
		cout << pq.top().row << " " << pq.top().col << "\n";
		pq.pop();
	}
}

int main() {

	struct_prioriy_queue();
}