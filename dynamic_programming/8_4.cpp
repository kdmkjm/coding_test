/*
* 피보나치 수열
* memoization
* 재귀 함수 사용 - bottom up
*/
#include <iostream>
using namespace std;

long long result[101];

int main()
{
	int x;
	cin >> x;

	result[1] = 1, result[2] = 1;;
	
	for (int i = 3; i < x + 1; i++)
	{
		if (result[i] != 0)
		{
			// 아무것도 안함
		}
		else
		{
			cout << "result계산" << "(" << i << ")" << '\n';
			result[i] = result[i - 1] + result[i - 2];
		}
	}

	cout << result[x] << '\n';
}