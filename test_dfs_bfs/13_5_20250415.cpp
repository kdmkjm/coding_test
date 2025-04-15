#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> num;
vector<int> sign;
int max_value, min_value;
void dfs(int i, int now)
{
    if(i == n)
    {
        max_value = max(max_value, now);
        min_value = min(min_value, now);
    }
    else
    {
        if(sign[0] > 0)
        {
            sign[0]--;
            dfs(i + 1, now + num[i]);
            sign[0]++;
        }
        if(sign[1] > 0)
        {
            sign[1]--;
            dfs(i + 1, now - num[i]);
            sign[1]++;
        }
        if(sign[2] > 0)
        {
            sign[2]--;
            dfs(i + 1, now * num[i]);
            sign[2]++;
        }
        if(sign[3] > 0)
        {
            sign[3]--;
            dfs(i + 1, now / num[i]);
            sign[3]++;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        num.push_back(tmp);
    }
    for(int i = 0; i < 4; i++)
    {
        int tmp = 0;
        cin >> tmp;
        sign.push_back(tmp);
    }
    max_value = -1e9;
    min_value = 1e9;

    dfs(1, num[0]);

    cout << max_value << '\n';
    cout << min_value << '\n';
}