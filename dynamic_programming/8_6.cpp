/*
* 개미 전사
*/
#include <iostream>
using namespace std;

int result[101];
int n;
int k[101];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		k[i + 1] = tmp;
	}

	result[1] = k[1];
	for (int i = 1; i < n + 1; i++)
	{
		result[i] = max(result[i - 2] + k[i], result[i-1]);
	}
	cout << result[n] << '\n';
}