#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int n, m, start;
vector<pair<int,int> > v[100001];
int d[100001];

void dijkstra(int start)
{
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));
    d[start] = 0;

    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist)   continue;
        for(int i = 0; i < v[now].size(); i++)
        {
            int cost = dist + v[now][i].second;
            if( cost < d[v[now][i].first])
            {
                d[v[now][i].first] = cost;
                pq.push(make_pair(-cost, v[now][i].first));
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