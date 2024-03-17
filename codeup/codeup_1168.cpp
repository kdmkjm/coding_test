#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;

	if (b == 1 || b == 2)
	{
		cout << 112 - (a / 10000) + 1;
	}
	else if (b == 3 || b == 4)
	{
		cout << 12 - (a / 10000) + 1;
	}
}