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
int graph[201][201];

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우) 
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(int x, int y) {
    // 큐(Queue) 구현을 위해 queue 라이브러리 사용 
    queue<pair<int, int> > q;
    q.push({ x, y });
    // 큐가 빌 때까지 반복하기 
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 현재 위치에서 4가지 방향으로의 위치 확인
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 미로 찾기 공간을 벗어난 경우 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 벽인 경우 무시
            if (graph[nx][ny] == 0) continue;
            // 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
            if (graph[nx][ny] == 1) {
                graph[nx][ny] = graph[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
    // 가장 오른쪽 아래까지의 최단 거리 반환
    return graph[n - 1][m - 1];
}

int main(void) {
    // N, M을 공백을 기준으로 구분하여 입력 받기
    cin >> n >> m;
    // 2차원 리스트의 맵 정보 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &graph[i][j]);
        }
    }
    // BFS를 수행한 결과 출력
    cout << bfs(0, 0) << '\n';
    return 0;
}