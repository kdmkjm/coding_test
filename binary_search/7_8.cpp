/*
* 떡볶이 떡 만들기
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

int main()
{
	int end = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		arr.push_back(tmp);
		if (end < tmp) end = tmp;
	}

	int start = 0;
	int result = 0;

	while (start <= end)
	{
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mid) total += arr[i] - mid;
		}
		if (total < m)
		{
			end = mid - 1;
		}
		else
		{
			result = mid;
			start = mid + 1;
		}
	}

	cout << result << '\n';
}