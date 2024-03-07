#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	if ( (a <= 170) || (b <= 170) || (c <= 170))
	{
		cout << "CRASH";
	}
	else
	{
		cout << "PASS";
	}
}