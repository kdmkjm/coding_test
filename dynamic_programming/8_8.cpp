/*
* 효율적인 화폐 구성
*/
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
		int tmp = 0;
		cin >> tmp;
		v.push_back(tmp);
	}

	vector<int> result(m + 1, 10001);

	result[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = v[i]; j <= m; j++)
		{
			if (result[j - v[i]] != 10001)
			{
				result[j] = min(result[j], result[j - v[i]] + 1);
			}
		}
	}

	if (result[m] == 10001)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << result[m] << '\n';
	}
}