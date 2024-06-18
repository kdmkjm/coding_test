/*
* 최단 경로
* 다익스트라 알고리즘
*/
#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int n, m, start;
// 간선 정보 저장 벡터
vector<pair<int, int>> v[10001];
// 최단 경로 코스트 저장 배열
int d[10001];
// 노드 방문 기록 저장 배열
bool visited[10001];

int getSmallestNode()
{
	int min_v = INF;
	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] < min_v && !visited[i])
		{
			min_v = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start)
{
	// 첫번째 노드 처리
	d[start] = 0;
	visited[start] = true;

	// 첫번째 노드로부터 거리를 코스트 저장 배열에 저장
	for (int i = 0; i < v[start].size(); i++)
	{
		d[v[start][i].first] = v[start][i].second;
	}

	// 시작 노드 제외 횟수만큼 반복 n-1
	for (int i = 0; i < n - 1; i++)
	{
		// 다음 대상 노드 취득 및 방문처리
		int now = getSmallestNode();
		visited[now] = true;
		// 해당 노드와 연결된 다른 노드 확인
		for (int j = 0; j < v[now].size(); j++)
		{
			int cost = d[now] + v[now][j].second;
			// 기존 코스트와 비교
			if (cost < d[v[now][j].first])
			{
				d[v[now][j].first] = cost;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	cin >> start;

	// 간선 정보 입력
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}

	// 코스트 미계산 배열 요소 임의의 값 INF로 초기화
	fill_n(d, 10001, INF);

	// 다익스트라
	dijkstra(start);

	// 모든 노드에 대한 최단 거리 출력
	for (int i = 1; i <= n; i++)
	{
		// 해당 노드의 코스트가 초기치(INF)라면
		if (d[i] == INF) cout << "도달할 수 없는 노드 " << '\n';
		else
			cout << i << "번째 노드까지의 최단 거리 " << d[i] << '\n';
	}
}