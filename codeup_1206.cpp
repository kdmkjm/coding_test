#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;

	if (a % b == 0)
	{
		cout << b << "*" << (a/b) << "=" << a;
	}
	else if (b % a == 0)
	{
		cout << a << "*" << (b/a) << "=" << b;
	}
	else
		cout << "none";
}