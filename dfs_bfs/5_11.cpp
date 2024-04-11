// DFS/BFS
// 미로 탈출
// 입력 조건
// 첫 번째 줄에 미로의 세로 길이 N과 가로 길이 M이 주어진다.
// 두 번째 줄부터 N+1 번째 줄까지 미로의 형태가 주어진다.
// 이때 괴물이 있는 부분은 0으로 괴물이 없는 부분은 1로 주어진다.
// 출력
// 최소 이동 칸의 개수를 출력한다.
/*
5 5
11111
10001
10111
11101
00001
*/
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[201][201];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int bfs(int a, int b)
{
	queue<pair<int,int>> q;
	q.push({ a,b });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 네 방향 위치 확인
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 공간밖은 무시
			if (nx < 0 || ny < 0 || nx >n || ny > m)
			{
				continue;
			}

			// 괴물이 있는 경우 무시
			if (map[nx][ny] == 0)
			{
				continue;
			}

			// 처음 방문한 곳은 기록
			if (map[nx][ny] == 1)
			{
				map[nx][ny] = map[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return map[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%1d", &map[i][j]);
		}
	}

	cout << bfs(0, 0);
}