#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m;
vector<pair<int,int> > house;
vector<pair<int,int> > chicken;

int calcDistance(vector<pair<int,int> > now)
{
    int result = 0;
    for(int i = 0; i < house.size(); i++)
    {
        int tmp = INF;
        int hx = house[i].first;
        int hy = house[i].second;
        for(int j = 0; j < now.size(); j++)
        {
            int nx = now[j].first;
            int ny = now[j].second;
            int distance = abs(nx-hx) + abs(ny-hy);
            tmp = min(tmp, distance);
        }
        result += tmp;
    }
    return result;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            if(a == 1)  house.push_back(make_pair(i,j));
            if(a == 2)  chicken.push_back(make_pair(i,j));
        }
    }

    vector<bool> v(chicken.size());
    fill(v.begin(), v.begin()+m, true);

    int result = INF;

    do
    {
        vector<pair<int,int> > now;
        for(int i = 0; i < chicken.size(); i++)
        {
            if(v[i])
            {
                now.push_back(make_pair(chicken[i].first,chicken[i].second));
            }
        }
        result = min(result, calcDistance(now));
    } while (prev_permutation(v.begin(), v.end()));
    cout << result << '\n';
}