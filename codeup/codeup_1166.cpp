#include <iostream>
using namespace std;

int main()
{
	int year = 0;
	cin >> year;

	if (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)))
	{
		cout << "Leap";
	}
	else
	{
		cout << "Normal";
	}
}