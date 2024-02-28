#include <iostream>
using namespace std;

int main()
{
	float a = 0.f, sum = 0.f;
	int b = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b;
		sum = sum + ((float)a * b);
	}

	cout << fixed;
	cout.precision(1);
	cout << sum;
}