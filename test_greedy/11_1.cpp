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

	int result = 0, cnt = 0;

	for (int i = 0; i < v.size(); i++)
	{
		cnt++;
		if (v[i] <= cnt)
		{
			result++;
			cnt = 0;
		}
	}

	cout << result << '\n';
}