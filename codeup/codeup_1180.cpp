#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	n = ((n / 10) + ((n % 10) * 10)) * 2;
	n %= 100;
	cout << n << '\n';

	if (n <= 50)
	{
		cout << "GOOD";
	}
	else
	{
		cout << "OH MY GOD";
	}
}