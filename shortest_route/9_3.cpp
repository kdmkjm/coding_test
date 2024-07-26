/*
* 플로이드  워셜 알고리즘
*/
#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

// 노드의 개수 n, 간선의 개수 m
int n, m;

// 최단 경로를 저장할 2차원 배열 생성
int graph[501][501];

int main()
{
	cin >> n;
	cin >> m;

	// 최단 경로 배열 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = INF;
		}
	}

	// 자기 자신 노드 호출 시 코스트 0
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				graph[i][j] = 0;
			}
		}
	}

	// 간선 정보 읽어오기
	for (int i = 0; i < m; i++)
	{
		// 시작 노드 a, 종료 노드 b, 코스트 c
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	// 플로이드 워셜 알고리즘 실행
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

	// 결과 출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == INF)
				cout << "도달할 수 없는 노드입니다" << " ";
			else
				cout << graph[i][j] << " ";
		}
		cout << '\n';
	}
}