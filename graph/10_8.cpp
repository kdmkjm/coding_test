// 크루슼칼 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, result, max_v;
int parent[100001];
vector<pair<int, pair<int, int>>> v;

int findParent(int x)
{
	if (x != parent[x])
		return parent[x] = findParent(parent[x]);
	return x;
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

	// 부모 배열 초기화
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

	// 코스트 단위로 정렬
	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++)
	{
		// 사이클일 경우
		if (findParent(v[i].second.first) == findParent(v[i].second.second))
			continue;
		else
		{
			unionParent(findParent(v[i].second.first), findParent(v[i].second.second));
			result += v[i].first;
			max_v = v[i].first;
		}
	}
	
	result -= max_v;
	cout << result << '\n';
}