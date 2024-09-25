#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m;
int graph[501][501];

int main()
{
    cin >> n;
    cin >> m;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            graph[i][j] = INF;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                graph[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(graph[i][j] == INF)  cout << "INF" <<  '\n';
            else cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
}