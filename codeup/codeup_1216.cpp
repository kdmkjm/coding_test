#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	
	// 홍보를 할 경우 이득
	// b - c

	// 홍보를 하지 않은 경우 이득
	// a

	if ((b - c) > a)
	{
		cout << "advertise";
	}
	else if (a > (b - c))
	{
		cout << "do not advertise";
	}
	else
		cout << "does not matter";
}