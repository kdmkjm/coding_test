#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	cout << fixed;
	cout.precision(2);
	cout << ((float)a + b + c) / 3;
}