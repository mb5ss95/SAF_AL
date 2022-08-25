#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int parents[10];
int GroupCnt[10]; // index : node��ȣ, value : �ش� node�� '��ǥ�� ��' �ش� �׷쿡 '�� ��'�� �ִ°�?
int GroupMaxNode[10]; // �ش� �׷쿡�� ���� node��ȣ�� ū �� <-

int Find(int now)
{
    if (parents[now] == now)
        return now;
    return parents[now] = Find(parents[now]);
}

void Union(int A, int B) // �׷쿡 ��ȭ�� �ִ� �κ�
{
    int pA = Find(A);
    int pB = Find(B);

    if (pA == pB) return; // A�� B�� �̹� ���� �׷��̿���. <- �ƹ��͵� ���� ����� ����
    
    // A�� B�� �ٸ� �׷��� ���
    // pA�� �������� ��ǥ�� ����
    parents[pB] = pA; // ��ǥ�� 1������ ����

    GroupCnt[pA] += GroupCnt[pB]; // pB�� ���� �ִ� ������ ���� ��ǥ�� pA���� �Ѱ���
    GroupCnt[pB] = 0; // pB�� '��ǥ���� ������ ��' ��ǥ�� �ƴϹǷ� ������ ����

    GroupMaxNode[pA] = max(GroupMaxNode[pA], GroupMaxNode[pB]);
    GroupMaxNode[pB] = -1;
}


int main()
{
	for (int i = 0; i < 10; i++)
	{
	    parents[i] = i; // �ڱ��ڽ��� ��ǥ��.
	    // GroupCnt �ʱ�ȭ
	    GroupCnt[i] = 1; // ��ΰ� '�ڱ��ڽ�'�� ��ǥ�ϱ� �� �׷츶�� 1���� ����
	    GroupMaxNode[i] = i; // �ڱ��ڽ��� ���� ũ��.
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