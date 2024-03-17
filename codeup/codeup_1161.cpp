#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	int result = 0;

	if (a % 2 == 0)
	{
		cout << "짝수+";
	}
	else
	{
		cout << "홀수+";
	}

	if (b % 2 == 0)
	{
		cout << "짝수=";
	}
	else
	{
		cout << "홀수=";
	}

	if ((a+b) % 2 == 0)
	{
		cout << "짝수";
	}
	else
	{
		cout << "홀수";
	}
}