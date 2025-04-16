#include <iostream>
#include <vector>
using namespace std;

int n, min_val, max_val;
vector<int> num;
vector<int> sign;

void dfs(int i, int now)
{
	if (i == n)
	{
		min_val = min(min_val, now);
		max_val = max(max_val, now);
	}
	else
	{
		// +
		if (sign[0] > 0)
		{
			sign[0]--;
			dfs(i + 1, now + num[i]);
			sign[0]++;
		}
		// -
		if (sign[1] > 0)
		{
			sign[1]--;
			dfs(i + 1, now - num[i]);
			sign[1]++;
		}
		// *
		if (sign[2] > 0)
		{
			sign[2]--;
			dfs(i + 1, now * num[i]);
			sign[2]++;
		}
		// /
		if (sign[3] > 0)
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
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	for (int i = 0; i < 4; i++)
	{
		int tmp;
		cin >> tmp;
		sign.push_back(tmp);
	}

	// 초기화
	min_val = 1e9;
	max_val = -1e9;

	dfs(1, num[0]);

	cout << max_val << '\n';
	cout << min_val << '\n';
}