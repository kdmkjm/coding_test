#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());

	int target = 1;

	for (int i = 0; i < v.size(); i++)
	{
		if (target < v[i]) break;
		target += v[i];
	}

	cout << target << '\n';
}