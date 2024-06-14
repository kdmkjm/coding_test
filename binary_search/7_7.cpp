/*
* 부품 찾기 - 집합 자료형 set container
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;


int n, m;
set<int> s;
vector<int> st;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		s.insert(x);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x = 0;
		cin >> x;
		st.push_back(x);
	}

	for (int i = 0; i < m; i++)
	{
		if (s.find(st[i]) == s.end())
		{
			cout << "no ";
		}
		else cout << "yes ";
	}
}