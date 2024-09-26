#include <iostream>
using namespace std;

int n, m;
int graph[100001];

int findParent(int a)
{
	if (a == graph[a])
	{
		return a;
	}
	return graph[a] = findParent(graph[a]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if (a > b)
	{
		graph[a] = b;
	}
	else
	{
		graph[a] = b;
	}
}

int main()
{
	cin >> n >> m;

	// 루트 노드 초기화(자신)
	for (int i = 1; i <= n; i++)
	{
		graph[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	// 사이클 판별
	if (graph[n] = graph[1])
	{
		cout << "in cycle" << '\n';
	}
	else
	{
		cout << "int not cycle" << '\n';
	}
}