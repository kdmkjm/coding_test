#include <iostream>
using namespace std;

int n, m;
int graph[100001];

int findParent(int a)
{
    if(graph[a] != a)
    {
        return graph[a] = findParent(graph[a]);
    }
    return a;
}

void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if(a < b)
    {
        graph[b] = a;
    }
    else
        graph[a] = b;
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        graph[i] = i;
    }

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    cout << "각 원소가 속한 집함: ";
    for(int i = 1; i <= n; i++)
    {
        cout << findParent(i) << " ";
    }
    cout << "\n";

    cout << "부모 테이블: ";
    for(int i = 1; i <= n; i++)
    {
        cout << graph[i] << " ";
    }
    cout << "\n";
}