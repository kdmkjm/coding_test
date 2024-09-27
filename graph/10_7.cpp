#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parent[100001];

int findParent(int x)
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main()
{
	cin >> n >> m;

	// 부모 노드 초기화
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	// 간선 입력
	for (int i = 0; i < m; i++)
	{
		int mode, a, b;
		cin >> mode >> a >> b;
		if (mode == 0)
		{
			// 팀 합치기 연산
			unionParent(a, b);
		}
		else if (mode == 1)
		{
			// 같은 팀 여부 확인 연산
			if (findParent(a) == findParent(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
		else
			cout << "잘못된 연산 번호 입니다." << '\n';
	}
}