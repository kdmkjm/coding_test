/*
* 피보나치 수열
* memoization
*/
#include <iostream>
#include <vector>
using namespace std;

long long calc_fibo(int  x, long long result[101])
{
	if (x == 1 || x == 2) return 1;

	if (result[x] != 0)
	{
		return result[x];
	}
	
	result[x] = calc_fibo(x - 1, result) + calc_fibo(x - 2, result);
	return result[x];
}
int main()
{
	long long result[101] = { 0, };
	int x = 0;
	cin >> x;
	cout << calc_fibo(x, result) << '\n';
}