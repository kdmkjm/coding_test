#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m;
vector<pair<int,int> > house;
vector<pair<int,int> > chicken;

int calcSum(vector<pair<int,int> > now)
{
    int result = 0;
    for(int i = 0; i < house.size(); i++)
    {
        int hx = house[i].first;
        int hy = house[i].second;
        int tmp = INF;
        for(int j = 0; j < now.size(); j++)
        {
            int nowx = now[i].first;
            int nowy = now[i].second;
            tmp = min(tmp, abs(nowx - hx) + abs(nowy - hy));
        }
        result += tmp;
    }
    return result;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if(a == 1)  house.push_back(make_pair(i,j));
            else if(a == 2) chicken.push_back(make_pair(i,j));
        }
    }

    int result = INF;

    vector<bool> v(chicken.size());
//    fill(v.begin(), v.begin() + m, true);
    for(int i = 0; i < m; i++)
    {
        v[i] = true;
    }

    do
    {
        vector<pair<int,int> > now;
        for(int i = 0; i < chicken.size(); i++)
        {
            if(v[i])
            {
                int vx = chicken[i].first;
                int vy = chicken[i].second;
                now.push_back(make_pair(vx,vy));
            }
        }
        result = min(result, calcSum(now));
        cout << result << " " << calcSum(now) <<'\n';
    }while(prev_permutation(v.begin(), v.end()));

//    cout << result << '\n';
}