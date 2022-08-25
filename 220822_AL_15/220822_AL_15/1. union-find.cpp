#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int parents[10];
int GroupCnt[10]; // index : node번호, value : 해당 node가 '대표일 때' 해당 그룹에 '몇 명'이 있는가?
int GroupMaxNode[10]; // 해당 그룹에서 가장 node번호가 큰 값 <-

int Find(int now)
{
    if (parents[now] == now)
        return now;
    return parents[now] = Find(parents[now]);
}

void Union(int A, int B) // 그룹에 변화를 주는 부분
{
    int pA = Find(A);
    int pB = Find(B);

    if (pA == pB) return; // A와 B가 이미 같은 그룹이였다. <- 아무것도 하지 말라고 무시
    
    // A와 B가 다른 그룹인 경우
    // pA를 최종적인 대표로 선발
    parents[pB] = pA; // 대표를 1명으로 통일

    GroupCnt[pA] += GroupCnt[pB]; // pB가 갖고 있던 정보를 최종 대표인 pA에게 넘겨줌
    GroupCnt[pB] = 0; // pB는 '대표에서 물러난 점' 대표가 아니므로 정보를 삭제

    GroupMaxNode[pA] = max(GroupMaxNode[pA], GroupMaxNode[pB]);
    GroupMaxNode[pB] = -1;
}


int main()
{
	for (int i = 0; i < 10; i++)
	{
	    parents[i] = i; // 자기자신이 대표다.
	    // GroupCnt 초기화
	    GroupCnt[i] = 1; // 모두가 '자기자신'이 대표니까 각 그룹마다 1명씩만 있음
	    GroupMaxNode[i] = i; // 자기자신이 제일 크다.
	}
	
	Union(1, 2);
	Union(2, 3);
	Union(1, 4);
	cout << GroupCnt[ Find(2) ] << "\n";
	Union(2, 5);
	Union(6, 7);
	Union(7, 8);
	Union(5, 8);
	cout << GroupCnt[ Find(3) ] << "\n";



	return 0;
}