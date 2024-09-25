#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int n, m, start;
vector<pair<int,int> > v[100001];
int d[100001];
bool visited[100001];

int getSmallestNode()
{
    int index = 0;
    int min_v = INF;

    // 방문하지 않은 노드중 최소 코스트의 노드 검색
    for(int i = 1; i <= n; i++)
    {
        if(d[i] < min_v && !visited[i])
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

    // 시작 노드와 연결된 간선 정보 저장
    for(int i = 0; i < v[start].size(); i++)
    {
        // 코스트 저장
        d[v[start][i].first] = v[start][i].second;
    }

    // 시작 노드 제외 나머지 노드 반복
    for(int i = 1; i < n; i++)
    {
        // 방문하지 않은 노드중 최소 코스트의 노드 검색
        int now = getSmallestNode();
        visited[now] = true;

        // now노드와 연결된 간선 비교
        for(int j = 0; j < v[now].size(); j++)
        {
            int cost = d[now] + v[now][j].second;
            if( cost < d[v[now][j].first])
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

    // 간선정보 입력
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
    }

    // 코스트 저장 배열 초기화
    fill_n(d, 100001, INF);

    // 다익스트라 알고리즘 호출
    dijkstra(start);
    
    // 결과 출력
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == INF)
            cout << "도달할 수 없는 노드입니다." << '\n';
        else
            cout << d[i] << '\n';
    }
}