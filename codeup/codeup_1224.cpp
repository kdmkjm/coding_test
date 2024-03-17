#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;

	if ((float)a / b > (float)c / d)
	{
		cout << ">";
	}
	else if ((float)a / b < (float)c / d)
	{
		cout << "<";
	}
	else
		cout << "=";
}