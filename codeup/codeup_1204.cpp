#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	if (10 < n && n <= 20)
	{
		cout << n << "th";
	}
	else if (n % 10 == 1)
	{
		cout << n << "st";
	}
	else if (n % 10 == 2)
	{
		cout << n << "nd";
	}
	else if (n % 10 == 3)
	{
		cout << n << "rd";
	}
	else
		cout << n << "th";
}