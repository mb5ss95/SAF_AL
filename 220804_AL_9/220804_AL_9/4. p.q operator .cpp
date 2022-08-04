#include <iostream>
#include <queue>
using namespace std;

//priority_queue<int, vector<int>, less<int>> q;
//priority_queue<int> q; //max heap (ū�� �켱����
//priority_queue<int, vector<int>, greater<int>> q; //(������ �켱����)

//��������
//1. ¦�� �켱
//2. ū�� �켱

//����Ʈ ����

struct node {
	int n;
};

bool operator<(node v, node t) {
	if (t.n % 2 == 0 && t.n % 2 == 1) return 1;
	if (t.n % 2 == 1 && t.n % 2 == 0) return 0;

	return t.n > v.n;
}

priority_queue<node> q;


int main() {

	q.push({ 1 });
	q.push({ 2 });
	q.push({ 5 });
	q.push({ 4 });
	q.push({ 6 });
	q.push({ 7 });

	while (!q.empty()) {
		cout << q.top().n;
		q.pop();
	}


	return 0;
}