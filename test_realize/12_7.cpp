#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m;
vector<pair<int,int> > house;
vector<pair<int,int> > chicken;

int getSum(vector<pair<int, int> > v)
{
	int result = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int hx = house[i].first;
		int hy = house[i].second;
		int tmp = INF;
		for (int j = 0; j < v.size(); j++)
		{
			int vx = v[j].first;
			int vy = v[j].second;
			tmp = min(tmp, abs(vx - hx) + abs(vy - hy));
		}
		result += tmp;
	}
	return result;
}

int main()
{
	cin >> n >> m;
	int result = INF;
	int tmp_v;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> tmp_v;
			
			if (tmp_v == 1)
				house.push_back(make_pair(i, j));
			else if (tmp_v == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	
	vector<bool> v(chicken.size());
	for (int i = 0; i < m; i++)
	{
		v[i] = true;
	}
	
	do
	{
		vector<pair<int, int> > now;
		for (int i = 0; i < chicken.size(); i++)
		{
			if (v[i])
			{
				int cx = chicken[i].first;
				int cy = chicken[i].second;
				now.push_back(make_pair(cx, cy));
			}
		}
		result = min(result, getSum(now));
	} while (prev_permutation(v.begin(), v.end()));
	
	cout << result << '\n';
}
