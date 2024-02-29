#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	if (a > b)
	{
		if (b > c)
		{
			cout << c;
		}
		else
		{
			cout << b;
		}
	}
	else
	{
		if (a > c)
		{
			cout << c;
		}
		else
		{
			cout << a;
		}
	}
}