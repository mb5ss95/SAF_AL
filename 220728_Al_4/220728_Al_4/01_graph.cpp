#include <iostream>
#include <vector>
using namespace std;

// 1. 인접행렬 기초 (feat. 반장선거)
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

// 2. (문제) 입력 정보를 토대로 인접 행렬 방식 저장해서 출력하기
// 4		<= node 개수
// 6		<= edge 개수
// 1 2		<= form to 정보 (edge 개수만큼)
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

// 3. 방향이 없는 인접 행렬
// 5		<= node 개수
// 4		<= edge 개수
// 1 2		<= from to 정보 (edge 개수만큼)
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

// 4. 방향이 있는 인접 리스트 (feat. vector)
//int main()
//{
//	vector<int> v[100];				// #include <vector>
//	int node, edge;
//	cin >> node >> edge;
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		v[from].push_back(to);		// push_back(data) : 맨 뒤에 공간을 추가하여 data 저장
//	}
//
//}

// 5. 방향이 없는 인접 리스트
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

// 6. 특정 node에서 갈 수 있는 node들 찾기 (Version. 인접 행렬)
// 5 8		<= node, edge 개수
// 1 2		<= from to 정보 (edge 개수만큼)
// 1 5
// 2 4
// 2 3
// 3 4
// 3 5
// 4 1
// 4 3
// 2		<= 특정 node
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

// 7. 특정 node에서 갈 수 있는 node들 찾기 (Version. 인접 리스트)
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