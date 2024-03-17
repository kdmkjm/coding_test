#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	if (c < 10)
	{
		cout << a << b << 0 << c;
	}
	else
	{
		cout << a << b << c;
	}
}