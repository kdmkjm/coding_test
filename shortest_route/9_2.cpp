/*
* 최단 경로
* 우선순위 큐를 이용한 다익스트라 알고리즘
*/
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int n, m, start;
vector<pair<int, int>> graph[100001];
int d[100001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	d[start] = 0;
	while (!pq.empty())
	{
		// 가장 거리가 짧은 노드 정보 꺼내기
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;
		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first])
			{
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	cin >> start;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	fill_n(d, 100001, INF);

	dijkstra(start);

	for (int i = 1; i <= n; i++)
	{
		if (d[i] == INF)
			cout << "도달할 수 없는 노드" << '\n';
		else
			cout << i << "번째 노드 까지의 최단 거리는 " << d[i] << '\n';
	}
}