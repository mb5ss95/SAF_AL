#include <iostream>
#include <queue>

using namespace std;

/*
default는 less임, 큰 값 우선 => less operator<
		          작은 값 우선으로 만들고 싶으면 -> greater operator>


템플릿 선언 부분을 보겠습니다.
template <?typename T,
			typename Container = vector<T>,
			typename Compare = less<typename Container::velue_type> >
class priority_queue;

기본 생성자 형식 
priority_queue < [Data Type] > [변수이름];
ex) priority_queue<int> pq;

내부 컨테이너 변경 
priority_queue < [Data Type], [Container Type] > [변수이름];
ex) priority_queue<int, deque<int> > pq;

정렬 기준 변경 
priority_queue < [Data Type], [Container Type], [정렬기준] > [변수이름];
ex) priority_queue<int , vector<int>, greater<int> > pq;
*/

struct node {
	int row;
	int col;
};

// a < b 로 비교하겠다
bool operator<(node a, node b) {
	// b가 우선순위가 높으면 ture
	// a가 우선순위가 높으면 false

	// row가 작은 것 우선, row가 같으면 col이 큰것 우선
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
	priority_queue<int> pq;  기본형, default less
	
	pq.push(5);// O(logN) 걸림
	pq.push(1);
	pq.push(4);
	pq.push(6);
	pq.push(2);
	pq.push(3);

	// 힙 소트라고 부름 O(N*logN) 걸림
	while (!pq.empty()) {
		cout << pq.top() << " "; // O(1)
		pq.pop(); //O(logN)
	}*/
	struct_prioriy_queue();
}