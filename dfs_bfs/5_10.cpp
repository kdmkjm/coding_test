// DFS/BFS
// 음료수 얼려먹기
// 입력 조건
// 첫 번째 줄에 얼음 틀의 세로 길이 N과 가로 길이 M이 주어진다.
// 두 번째 줄부터 N+1 번째 줄까지 얼음 틀의 형태가 주어진다.
// 이때 구멍이 뚫려있는 부분은 0, 그렇지 않은 부분은 1이다.
// 출력
// 한 번에 만들 수 있는 아이스크림의 개수를 출력한다.
// 예시

#include <iostream>
#include <stdio.h>
using namespace std;

int n, m;
int map[1000][1000];

bool dfs(int x, int y)
{
	// 탐색 시 범위를 벗어날 경우
	if (x < 0 || y < 0 || x >= n || y >=m)
	{
		return false;
	}

	// 현재 노드를 방문하지 않았다면
	if (map[x][y] == 0)
	{
		// 현재 노드 방문 처리
		map[x][y] = 1;

		dfs(x + 1, y);
		dfs(x, y + 1);
		dfs(x - 1, y);
		dfs(x, y - 1);

		return true;
	}
	else
		return false;
}

int main()
{
	int cnt = 0;
	// 세로 길이 n과 가로 길이 m 입력
	cin >> n >> m;
	// 얼음 틀의 형태 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dfs(i, j) == true)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
}