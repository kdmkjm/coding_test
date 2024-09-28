#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a <= m)
		{
			v.push_back(a);
		}
	}

	int result = 0;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i] != v[j])
				result++;
		}
	}

	cout << result << '\n';
}