/*
* 미래 도시
*/
#include <iostream>
#define INF 1e9
using namespace std;

// 회사의 개수 n, 경로의 개수 m, 경유지 x, 목적지 k
int n, m, x, k;
// 최단 경로 저장 2차원 배열
int graph[101][101];

int main()
{
	cin >> n >> m;

	// 배열 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = INF;
		}
	}

	// 본인 호출 코스트 0
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) graph[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		// 코스트는 1고정
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	cin >> x >> k;

	// 플로이드 워셜 알고리즘 실행
	for (int z = 1; z <= n; z++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][z] + graph[z][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

	// 1 -> k -> x로 가는 최단 거리 산출
	int total = graph[1][k] + graph[k][x];
	
	if (total >= INF)
		cout << -1 << '\n';
	else
		cout << total << '\n';
}