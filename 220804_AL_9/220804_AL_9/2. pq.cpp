#include <iostream>
#include <queue>

using namespace std;

/*
default는 less임, 큰 값 우선 => less operator<
				  작은 값 우선으로 만들고 싶으면 -> greater operator>
*/

struct node {
	int row;
	int col;
};

struct cmp { //비교하는 구조(우선순위)
	bool operator()(node a, node b) {
		//우선순위 작성
		//b가 우선순위가 높으면 true
		//a가 우선순위가 높으면 flase

		//row가 큰것 우선, row가 같으면 col이 작은게 우선
		if (a.row > b.row) return false;
		if (a.row < b.row) return true;

		//row가 같은 경우
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