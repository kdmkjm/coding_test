#include <iostream>
using namespace std;

int main()
{
	float a = 0, b = 0, c = 0;
	cin >> a >> b;

	c = a + b;
	if ((a - b) > c) { c = a - b; }
	if ((b - a) > c) { c = b - a; }
	if ((a * b) > c) { c = a * b; }
	if (((float)a / b) > c) { c = (float)a / b; }
	if (((float)b / a) > c) { c = (float)b / a; }

	float d = 1;
	for (int i = 0; i < b; i++)
	{
		d *= a;
	}
	if (d > c) { c = d; }
	d = 1;
	for (int i = 0; i < a; i++)
	{
		d *= b;
	}
	if (d > c) { c = d; }

	cout << fixed;
	cout.precision(6);
	cout << c;
}