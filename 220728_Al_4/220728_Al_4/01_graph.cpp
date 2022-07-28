#include <iostream>
#include <vector>
using namespace std;

// 1. ������� ���� (feat. ���弱��)
//int main()
//{
//	int n;
//	int arr[11][11] = { 0 };
//	int maxSum = -1;
//	int maxTo = -1;
//	cin >> n;
//
//	for (int from = 1; from <= n; from++)
//	{
//		for (int to = 1; to <= n; to++)
//		{
//			cin >> arr[from][to];
//		}
//	}
//
//	for (int to = 1; to <= n; to++)
//	{
//		int sum = 0;
//		for (int from = 1; from <= n; from++)
//		{
//			if (arr[from][to] == 1)
//				sum++;
//		}
//		cout << to << ":" << sum << "\n";
//		if (sum > maxSum)
//		{
//			maxSum = sum;
//			maxTo = to;
//		}
//	}
//
//	cout << maxSum << " " << maxTo;
//	
//	return 0;
//}

// 2. (����) �Է� ������ ���� ���� ��� ��� �����ؼ� ����ϱ�
// 4		<= node ����
// 6		<= edge ����
// 1 2		<= form to ���� (edge ������ŭ)
// 2 3
// 2 4
// 3 4
// 4 2
// 4 3
//int main()
//{
//	int arr[10][10] = { 0 };
//	int node, edge;
//	cin >> node >> edge;
//
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		arr[from][to] = 1;
//	}
//
//	for (int from = 1; from <= node; from++)
//	{
//		for (int to = 1; to <= node; to++)
//		{
//			cout << arr[from][to] << " ";
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}

// 3. ������ ���� ���� ���
// 5		<= node ����
// 4		<= edge ����
// 1 2		<= from to ���� (edge ������ŭ)
// 1 5
// 3 5
// 3 4
//int main()
//{
//	int arr[100][100] = { 0 };
//	int node, edge;
//	cin >> node >> edge;
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		arr[from][to] = 1;
//		arr[to][from] = 1;
//	}
//
//	for (int from = 1; from <= node; from++)
//	{
//		for (int to = 1; to <= node; to++)
//		{
//			cout << arr[from][to] << " ";
//		}
//		cout << "\n";
//	}
//	
//	return 0;
//}

// 4. ������ �ִ� ���� ����Ʈ (feat. vector)
//int main()
//{
//	vector<int> v[100];				// #include <vector>
//	int node, edge;
//	cin >> node >> edge;
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		v[from].push_back(to);		// push_back(data) : �� �ڿ� ������ �߰��Ͽ� data ����
//	}
//
//}

// 5. ������ ���� ���� ����Ʈ
//int main()
//{
//	vector<int> v[100];
//	int node, edge;
//	cin >> node >> edge;
//
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		v[from].push_back(to);
//		v[to].push_back(from);
//	}
//}

// 6. Ư�� node���� �� �� �ִ� node�� ã�� (Version. ���� ���)
// 5 8		<= node, edge ����
// 1 2		<= from to ���� (edge ������ŭ)
// 1 5
// 2 4
// 2 3
// 3 4
// 3 5
// 4 1
// 4 3
// 2		<= Ư�� node
//int main()
//{
//	int node, edge;
//	int arr[10][10] = { 0 };
//	int startFrom;
//	cin >> node >> edge;
//
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//
//		arr[from][to] = 1;
//	}
//
//	cin >> startFrom;
//
//	for (int to = 1; to <= node; to++)
//	{
//		if (arr[startFrom][to] == 1) 
//			cout << to << " ";
//	}
//
//	return 0;
//}

// 7. Ư�� node���� �� �� �ִ� node�� ã�� (Version. ���� ����Ʈ)
//int main()
//{
//	int node, edge;
//	cin >> node >> edge;
//	vector<int> v[100];
//
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//
//		v[from].push_back(to);
//	}
//
//	int startNode;
//	cin >> startNode;
//
//	for (int x = 0; x < v[startNode].size(); x++)
//	{
//		cout << v[startNode][x] << " ";
//	}
//}