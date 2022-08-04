#include <iostream>
#include <queue>

using namespace std;

/*
default�� less��, ū �� �켱 => less operator<
		          ���� �� �켱���� ����� ������ -> greater operator>


���ø� ���� �κ��� ���ڽ��ϴ�.
template <?typename T,
			typename Container = vector<T>,
			typename Compare = less<typename Container::velue_type> >
class priority_queue;

�⺻ ������ ���� 
priority_queue < [Data Type] > [�����̸�];
ex) priority_queue<int> pq;

���� �����̳� ���� 
priority_queue < [Data Type], [Container Type] > [�����̸�];
ex) priority_queue<int, deque<int> > pq;

���� ���� ���� 
priority_queue < [Data Type], [Container Type], [���ı���] > [�����̸�];
ex) priority_queue<int , vector<int>, greater<int> > pq;
*/

struct node {
	int row;
	int col;
};

// a < b �� ���ϰڴ�
bool operator<(node a, node b) {
	// b�� �켱������ ������ ture
	// a�� �켱������ ������ false

	// row�� ���� �� �켱, row�� ������ col�� ū�� �켱
	if (a.row < b.row) return 1;
	if (a.row > b.row) return 0;

	if (a.col < b.col) return 1;
	if (a.col > b.col) return 0;

	return 0;
}

void struct_prioriy_queue() {
	priority_queue<node> pq;
	pq.push({ 1,2 }); 
	pq.push({ 2,3 });
	pq.push({ 4,2 });
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
	//priority_queue<int, vector<int>, greater<int>> pq 

	/*
	priority_queue<int> pq;  �⺻��, default less
	
	pq.push(5);// O(logN) �ɸ�
	pq.push(1);
	pq.push(4);
	pq.push(6);
	pq.push(2);
	pq.push(3);

	// �� ��Ʈ��� �θ� O(N*logN) �ɸ�
	while (!pq.empty()) {
		cout << pq.top() << " "; // O(1)
		pq.pop(); //O(logN)
	}*/
	struct_prioriy_queue();
}