#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> num;
vector<int> mark;
int max_value = -1e9;
int min_value = 1e9;

void dfs(int i, int now)
{
    if(i == n)
    {
        min_value = min(min_value, now);
        max_value = max(max_value, now);
    }
    else
    {
        if(mark[0] > 0)
        {
            mark[0]--;
            dfs(i + 1, now + num[i]);
            mark[0]++;
        }
        if(mark[1] > 0)
        {
            mark[1]--;
            dfs(i + 1, now - num[i]);
            mark[1]++;
        }
        if(mark[2] > 0)
        {
            mark[2]--;
            dfs(i + 1, now * num[i]);
            mark[2]++;
        }
        if(mark[3] > 0)
        {
            mark[3]--;
            dfs(i + 1, now / num[i]);
            mark[3]++;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }
    for(int i = 0; i < 4; i++)
    {
        int a;
        cin >> a;
        mark.push_back(a);
    }

    // dfs
    dfs(1, num[0]);
    cout << max_value << '\n';
    cout << min_value << '\n';
}