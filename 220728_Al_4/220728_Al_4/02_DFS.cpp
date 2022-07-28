#include <iostream>
#include <vector>
using namespace std;

// 1. DFS 기초
//int arr[6][6];
//int node;
//
//void dfs(int now)
//{
//	cout << now << " ";
//
//	for (int next = 1; next <= node; next++)
//	{
//		if (arr[now][next] == 0)
//			continue;
//		dfs(next);
//	}
//}
//
//int main()
//{
//	cin >> node;
//
//	for (int i = 0; i < node - 1; i++)
//	{
//		int parent, child;
//		cin >> parent >> child;
//		arr[parent][child] = 1;
//	}
//
//	dfs(1);
//}

// 2. (문제) 인접 리스트로 DFS 해보기
// 5			<= node 개수
// 1 2			<= parent child
// 1 3
// 2 4
// 2 5

//int node;
//vector<int> v[6];
//
//void dfs(int now)
//{
//	cout << now << " ";
//
//	for (int i = 0; i < v[now].size(); i++)
//	{
//		int next = v[now][i];
//		dfs(next);
//	}
//}
//
//int main()
//{
//	cin >> node;
//
//	for (int i = 0; i < node - 1; i++)
//	{
//		int parent, child;
//		cin >> parent >> child;
//		v[parent].push_back(child);
//	}
//
//	dfs(1);
//}

// 3-1. a에서 b로 갈 수 있는가?
// 7		<= node
// 5		<= edge
// 1 2		<= parent, child
// 2 4
// 2 5
// 3 6
// 6 7
// 1 3		<= a에서 b로 갈 수 있는가?

//int node, edge;
//int answer;
//int a, b;
//int arr[10][10];
//
//void dfs(int now)
//{
//	if (now == b)
//	{
//		answer = 1;
//		return;
//	}
//
//	for (int next = 1; next <= node; next++)
//	{
//		if (arr[now][next] == 0) continue;
//		dfs(next);
//	}
//}
//
//int main()
//{
//	cin >> node >> edge;
//
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		arr[from][to] = 1;
//	}
//
//	cin >> a >> b;
//
//	dfs(a);
//
//	cout << answer;
//
//	return 0;
//}

// 3-2. a에서 b로 갈 수 있는가? (내가 어떤 점들을 들렸는가를 기록)
// 7		<= node
// 5		<= edge
// 1 2		<= parent, child
// 2 4
// 2 5
// 3 6
// 6 7
// 1 3		<= a에서 b로 갈 수 있는가?

//int node, edge;
//int answer;
//int arr[10][10];
//int used[10];
//
//void dfs(int now)
//{
//	for (int next = 1; next <= node; next++)
//	{
//		if (arr[now][next] == 0) continue;
//
//		used[next] = 1;
//		dfs(next);
//	}
//}
//
//int main()
//{
//	cin >> node >> edge;
//
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		arr[from][to] = 1;
//	}
//
//	int a, b;
//	cin >> a >> b;
//
//	used[a] = 1;
//	dfs(a);
//
//	cout << used[b];
//
//	return 0;
//}

// 3-3. a에서 b로 갈 수 있는가? (지금 내가 어떤 경로로 이동중인가???) (feat. vector)
//int node, edge;
//int answer;
//int arr[10][10];
//vector<int> path;
//
//void dfs(int now)
//{
//	for (int next = 1; next <= node; next++)
//	{
//		if (arr[now][next] == 0) continue;
//
//		path.push_back(next);
//		dfs(next);
//		path.pop_back();		// pop_back() : vector의 마지막 data를 삭제
//	}
//}
//
//int main()
//{
//	cin >> node >> edge;
//
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		arr[from][to] = 1;
//	}
//
//	int a, b;
//	cin >> a >> b;
//
//	path.push_back(a);
//	dfs(a);
//	path.pop_back();
//
//	return 0;
//}

// 3-4. used와 path 합치기
//int node, edge;
//int answer;
//int arr[10][10];
//int used[10];
//vector<int> path;
//
//void dfs(int now)
//{
//	for (int next = 1; next <= node; next++)
//	{
//		if (arr[now][next] == 0) continue;
//		
//		used[next] = 1;
//		path.push_back(next);
//		dfs(next);
//		path.pop_back();
//		used[next] = 0;
//	}
//}
//
//int main()
//{
//	cin >> node >> edge;
//
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		arr[from][to] = 1;
//	}
//
//	int a, b;
//	cin >> a >> b;
//
//	used[a] = 1;
//	path.push_back(a);
//	dfs(a);
//	path.pop_back();
//	used[a] = 0;
//
//	return 0;
//}

// 4. (문제) 무방향 그래프 모든 점 들려보기
//5
//6
//1 2
//1 3
//1 4
//2 5
//3 4
//4 5

//int node, edge;
//int arr[10][10];
//int used[10];
//
//void dfs(int now)
//{
//	cout << now << " ";
//
//	for (int next = 1; next <= node; next++)
//	{
//		if (arr[now][next] == 0) continue;
//		
//		if (used[next] == 1) continue;
//
//		used[next] = 1;
//		dfs(next);
//	}
//}
//
//
//int main()
//{
//	cin >> node >> edge;
//	for (int i = 0; i < edge; i++)
//	{
//		int from, to;
//		cin >> from >> to;
//		arr[from][to] = 1;
//		arr[to][from] = 1;
//	}
//
//	used[1] = 1;
//	dfs(1);
//}

// 5. (문제) 무방향 그래프 a에서 b로 가는 경로
//5
//6
//1 2
//1 3
//1 4
//2 5
//3 4
//4 5

int node, edge;
int arr[10][10];
int used[10];
vector<int> path;

void dfs(int now)
{
	if (now == 5)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int next = 1; next <= node; next++)
	{
		if (arr[now][next] == 0) continue;
		
		if (used[next] == 1) continue;

		used[next] = 1;
		path.push_back(next);
		dfs(next);
		path.pop_back();
		used[next] = 0;
	}
}


int main()
{
	cin >> node >> edge;
	for (int i = 0; i < edge; i++)
	{
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1;
	}

	used[1] = 1;
	path.push_back(1);
	dfs(1);
	path.pop_back();
	used[1] = 0;
}

