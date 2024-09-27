#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> v[100001];	// 간선 정보
int indegree[100001];	// 진입차수

void topologySort()
{
	vector<int> result;
	queue<int> q;

	// 진입차수가 0인 노드를 큐에 삽입
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		// 큐(진입차수가 0)에서 제거
		int now = q.front();
		q.pop();

		// 큐에서 제거한 노드 결과에 저장
		result.push_back(now);

		// 현재 노드에 연결된 간선 제거
		for (int i = 0; i < v[now].size(); i++)
		{
			indegree[v[now][i]]--;
			// 진입차수가 0인 애들 찾기
			if (indegree[v[now][i]] == 0)
				q.push(v[now][i]);
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	topologySort();
}