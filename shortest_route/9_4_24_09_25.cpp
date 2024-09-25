#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m, dx, dk;
int graph[101][101];

int main()
{
	cin >> n >> m;

	// 코스트 저장 2차원 배열 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = INF;

			// 시작 노드와 종료 노드가 같은 경우 코스트 0 저장
			if (i == j)
			{
				graph[i][j] = 0;
			}
		}
	}

	// 간선의 정보 입력
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	// 목표 노드 x, 중간 노드 k 입력 받기
	cin >> dx >> dk;

	// 플로이드 워셜 알고리즘
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	// 도달 여부 체크
	if (graph[1][dk] == INF || graph[dk][dx] == INF)
	{
		cout << -1 << '\n';
	}
	else
	{
		int result = graph[1][dk] + graph[dk][dx];
		cout << result << '\n';
	}
}