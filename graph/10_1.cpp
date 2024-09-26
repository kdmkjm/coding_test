#include <iostream>
using namespace std;

int n, m;
int parent[101];

int find_parent(int now)
{
    if(parent[now] != now)
    {
        return find_parent(parent[now]);
    }
    return now;
}

void union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    if(a > b)   parent[a] = b;
    else        parent[b] = a;
}

int main()
{
    cin >> n >> m;

    // 초기화
    fill_n(parent, 101, 0);

    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        union_parent(a,b);
    }

    cout << "각 원소가 속한 집합: ";
    for(int i = 1; i <= n; i++)
    {
        cout << find_parent(i) << " ";
    }
    cout << "\n";

    cout << "부모 테이블: ";
    for(int i = 1; i <= n; i++)
    {
        cout << parent[i] << " ";
    }
}