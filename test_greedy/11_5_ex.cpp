#include <iostream>
using namespace std;

int n, m;
int arr[11];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr[a]++;
	}

	int result = 0;

	for (int i = 1; i <= m; i++)
	{
		n -= arr[i];
		result += arr[i] * n;
	}

	cout << result << '\n';
}