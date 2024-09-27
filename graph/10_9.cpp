#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int indegree[501];
vector<int> v[501];
int times[501];

void topologySort()
{
	int result[501] = { 0, };
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		result[i] = times[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++)
		{
			result[v[now][i]] = max(result[v[now][i]], 
				result[now] + times[v[now][i]]);
			indegree[v[now][i]]--;
			if (indegree[v[now][i]] == 0)
				q.push(v[now][i]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << '\n';
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		times[i] = x;
		while (true)
		{
			cin >> x;
			if (x == -1)	break;
			indegree[i]++;
			v[x].push_back(i);
		}
	}

	topologySort();
}