/*
* 피보나치 수열
*/
#include <iostream>
using namespace std;

int calc_fibo(int  x)
{
	if (x == 1 || x == 2) return 1;
	else
		return calc_fibo(x - 1) + calc_fibo(x - 2);
}
int main()
{
	int x = 0;
	cin >> x;
	cout << calc_fibo(x) << '\n';
}