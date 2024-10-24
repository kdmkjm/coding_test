#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9 // 임의의 최댓값 설정용
using namespace std;

int n, m;
vector<pair<int,int> > house;   // 집의 좌표를 저장할 벡터
vector<pair<int,int> > chicken; // 치킨집의 좌표를 저장할 벡터

int getDistance(vector<pair<int,int> > now)
{
    int result = 0;
    for(int i = 0; i < house.size(); i++)
    {
        int hx = house[i].first;
        int hy = house[i].second;
        int tmp = INF;
        for(int j = 0; j < now.size(); j++)
        {
            int nx = now[j].first;
            int ny = now[j].second;
            tmp = min(tmp, abs(nx-hx)+abs(ny-hy));
        }
        result += tmp;
    }
    return result;
}

int main()
{
    cin >> n >> m;
    int result = INF;
    for(int i = 0; i < n; i++)  // 도시의 정보 입력
    {
        for(int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            if(a == 1)  house.push_back(make_pair(i,j));
            else if(a == 2) chicken.push_back(make_pair(i,j));
        }
    }

    vector<bool> v(chicken.size()); // 순열 계산용 벡터 생성
    fill(v.begin(), v.begin() + m, true);   // chicken.size()중 m개의 순열계산을 위해 내림차순으로 설정

    // 전체 순열 경우의 수 만큼 반복
    do
    {
        vector<pair<int,int> > now;
        for(int i = 0; i < chicken.size(); i++)
        {
            if(v[i])    // 해당 치킨집이 남아있다면    
            {
                now.push_back(make_pair(chicken[i].first, chicken[i].second));
            }
        }
        result = min(result, getDistance(now));
    } while (prev_permutation(v.begin(), v.end()));
    cout << result << '\n';
}