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
int graph[1000][1000];

// DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
bool dfs(int x, int y) {
    // 주어진 범위를 벗어나는 경우에는 즉시 종료
    if (x <= -1 || x >= n || y <= -1 || y >= m) {
        return false;
    }
    // 현재 노드를 아직 방문하지 않았다면
    if (graph[x][y] == 0) {
        // 해당 노드 방문 처리
        graph[x][y] = 1;
        // 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
        dfs(x - 1, y);
        dfs(x, y - 1);
        dfs(x + 1, y);
        dfs(x, y + 1);
        return true;
    }
    return false;
}

int main() {
    // N, M을 공백을 기준으로 구분하여 입력 받기
    cin >> n >> m;
    // 2차원 리스트의 맵 정보 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &graph[i][j]);
        }
    }
    // 모든 노드(위치)에 대하여 음료수 채우기
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 현재 위치에서 DFS 수행
            if (dfs(i, j)) {
                result += 1;
            }
        }
    }
    cout << result << '\n'; // 정답 출력 
}