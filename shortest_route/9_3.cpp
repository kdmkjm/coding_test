/*
최단 경로
플로이드 워셜 알고리즘
모든 노드에서 모든 노드로의 최단 경로 구하는 알고리즘
*/
#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

// 노드의 갯수 n, 간선의 갯수 m
int n, m;
// 최단 경로를 저장할 2차원 배열 생성
int graph[501][501];

int main()
{
	cin >> n >> m;
	
	// 2차원 배열 초기화
	for (int i = 0; i < 501; i++)
	{
		fill_n(graph[i],  + 501, INF);
	}

	// 자기 자신인 경우 0으로 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) graph[i][j] = 0;
		}
	}
	// 간선 정보 입력
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	// 점화식에 따른 알고리즘 수행
	// Dab = min(Dab, Dak + Dkb)
	for (int k = 1; k <= n; k++)
	{
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	// 결과 출력
	for (int a = 1; a <= n; a++)
	{
		for (int b = 1; b <= n; b++)
		{
			if (graph[a][b] == INF)
				cout << "도달할 수 없는 노드입니다" << ' ';
			else
				cout << graph[a][b] << ' ';
		}
		cout << '\n';
	}
}