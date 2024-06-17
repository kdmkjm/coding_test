/*
* 최단 경로
* 다익스트라 알고리즘
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9	// 무한
using namespace std;

// 노드의 갯수 n, 간선의 갯수 m, 시작 노드 번호 start
int n, m, start;
vector<pair<int, int>> graph[100001];
bool visited[100001];
// 최단 거리 테이블
int d[100001];

// 방문하지 않은 노드 중 최단 거리가 짧은 노드 번호 반환
int getSmallNode()
{
	int min_val = INF;
	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] < min_val && !visited[i])
		{
			min_val = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start)
{
	d[start] = 0;
	visited[start] = true;
	for (int j = 0; j < graph[start].size(); j++)
	{
		// start(0)와 연결된 노드의 최단 거리 설정
		d[graph[start][j].first] = graph[start][j].second;
	}
	// 노드 갯수만큼 반복(단 시작 노드는 제외)
	for (int i = 0; i < n - 1; i++)
	{
		// 최단 거리가 짧은 노드 처리
		int now = getSmallNode();
		visited[now] = true;
		// 해당 노드와 연결된 다른 노드 확인
		for (int j = 0; j < graph[now].size(); j++)
		{
			int cost = d[now] + graph[now][j].second;
			// 기존 코스트보다 짧은 경우
			if (cost < d[graph[now][j].first])
			{
				d[graph[now][j].first] = cost;
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
		// 간선 정보 입력
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back(make_pair(y, z));
	}

	fill_n(d, 100001, INF);
	dijkstra(start);
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == INF)
		{
			cout << "INFINITY" << '\n';
		}
		else
			cout << d[i] << '\n';
	}
}