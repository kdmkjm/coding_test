// factorial 구현
// 1. 반복
// 2. 재귀함수

#include <iostream>
using namespace std;

int a = 5;

int cal_fac_iter(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}

	return result;
}
int cal_fac_rec(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	return n * cal_fac_rec(n-1);
}

int main()
{
	cout << "반복문 결과: " << cal_fac_iter(a) << '\n';
	cout << "재귀함수 결과: " << cal_fac_rec(a) << '\n';
}