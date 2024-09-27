#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int parent[100001];
vector<pair<int, pair<int, int>>> v;
int result = 0;

int findParent(int a)
{
	if (a == parent[a])
		return a;
	else
		return parent[a] = findParent(parent[a]);
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

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++)
	{
		// 사이클 여부 확인
		// 사이클 존재
		if (findParent(v[i].second.first) == findParent(v[i].second.second))
			continue;
		// 사이클 존재 x -> union
		else
		{
			unionParent(v[i].second.first, v[i].second.second);
			result += v[i].first;
		}
	}

	cout << result << '\n';
}