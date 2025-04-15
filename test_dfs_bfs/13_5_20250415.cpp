#include <iostream>
#include <vector>
using namespace std;

int n, max_value, min_value;
vector<int> num;
vector<int> sign;

void dfs(int i, int now)
{
	if (i == n)
	{
		max_value = max(now, max_value);
		min_value = min(now, min_value);
	}
	if (sign[0] > 0)
	{
		sign[0]--;
		dfs(i + 1, now + num[i]);
		sign[0]++;
	}
	if (sign[1] > 0)
	{
		sign[1]--;
		dfs(i + 1, now - num[i]);
		sign[1]++;
	}
	if (sign[2] > 0)
	{
		sign[2]--;
		dfs(i + 1, now * num[i]);
		sign[2]++;
	}
	if (sign[3] > 0)
	{
		sign[3]--;
		dfs(i + 1, now / num[i]);
		sign[3]++;
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

	max_value = -1e9;
	min_value = 1e9;

	dfs(1, num[0]);

	cout << max_value << '\n';
	cout << min_value << '\n';
}