#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	// 나이
	cin >> a;

	// 태어난 년도
	b = 2012 - a + 1;

	if (b < 2000)
	{
		cout << b % 100 << " " << 1;
	}
	else
	{
		cout << b % 100 << " " << 3;
	}
}