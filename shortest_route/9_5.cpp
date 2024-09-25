#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int  n, m, start;
vector<pair<int, int>> v[30001];
int d[30001];
bool visited[30001];

int getSmallestNode()
{
	int index = 0;
	double min_v = INF;

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
	// 시작 노드 방문 처리
	d[start] = 0;
	visited[start] = true;

	// 시작 노드 연결 간선 코스트 저장
	for (int i = 0; i < v[start].size(); i++)
	{
		d[v[start][i].first] = v[start][i].second;
	}

	// 시작 노드 제외 노드 수 분 반복
	for (int i = 1; i < n; i++)
	{
		int now = getSmallestNode();
		visited[now] = true;

		// 시작 노드를 now로한 사이즈만큼 반복
		for (int j = 0; j < v[now].size(); j++)
		{
			// 코스트 비교
			int cost = d[now] + v[now][j].second;
			if (d[v[now][j].first] > cost)
				d[v[now][j].first] = cost;
		}
	}
}

int main()
{
	cin >> n >> m >> start;
	
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
	}

	// 코스트 저장 벡터 초기화
	fill_n(d, 30001, INF);

	// 다익스트라 알고리즘
	dijkstra(start);

	// 결과 출력
	int cnt = 0, distance = 0;

	for (int i = 1; i <= n; i++)
	{
		if (d[i] != INF)
		{
			cnt++;
			if(distance < d[i])
				distance = d[i];
		}
	}

	cout << cnt - 1 << " " << distance << '\n';
}