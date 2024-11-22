#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;             // 도시의 개수, 도로의 개수, 거리 정보, 출발 도시의 번호
vector<int> graph[300001];  // 도로 정보 저장용
vector<int> d(300001, -1);  // 총 거리 저장용

int main()
{
    cin >> n >> m >> k >> x;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    // 출발 도시 정보 초기화
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0; i < graph[now].size(); i++)
        {
            int nextNode = graph[now][i];
            if(d[nextNode] == -1)
            {
                d[nextNode] = d[now] + 1;
                q.push(nextNode);
            }
        }
    }
    bool check = false;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == k)
        {
            cout << i << '\n';
            check = true;
        }
    }
    if(!check)  cout << -1 << '\n';
}