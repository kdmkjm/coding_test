#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int n, m, start;
vector<pair<int,int> > v[100001];
int d[100001];
bool visited[100001];

int getSmallestNode(void)
{
    int index = 0;
    int min_v = INF;

    for(int i = 1; i <= n; i++)
    {
        if(d[i] < min_v && !visited[i])
        {
            index = i;
            min_v = d[i];
        }
    }

    return index;
}

void dijkstra(int start)
{
    d[start] = 0;
    visited[start] = true;

    for(int i = 0; i < v[start].size(); i++)
    {
        d[v[start][i].first] = v[start][i].second;
    }

    // 시작 노드 제외 남은 노드 수만큼 반복
	for (int i = 1; i < n; i++)
	{
		// 시작 노드에서 가장 코스트가 적은 노드찾는 함수 호출
		int now = getSmallestNode();
		// 해당 노드 방문 처리
		visited[now] = true;

		// now 노드와 연결된 다른 노드 확인
		for (int j = 0; j < v[now].size(); j++)
		{
			// now 노드와 연결 된 노드
			// 최단 거리 비교 : 최단 거리 배열에 들어있는 코스트 vs now 노드를 거쳐서 가는 코스트
			int cost = d[now] + v[now][j].second;
			if (d[v[now][j].first] > cost)
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

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
    }

    fill_n(d, 100001, INF);

    // main function
    dijkstra(start);

    for(int i = 1; i <= n; i++)
    {
        if(d[i] == INF) cout << "you cannot reach that node" << '\n';
        else    cout << "you can reach No " << i << "node. shortest cost is " << d[i] << '\n';
    }
}