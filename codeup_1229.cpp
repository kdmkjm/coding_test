#include <iostream>
using namespace std;

int main()
{
	double a = 0, b = 0, bmi = 0;
	cin >> a >> b;
	// 표준몸무게
	double c = 0;

	if (a > 160)
	{
		c = (a - 100) * 0.9;
	}
	else if (a > 150)
	{
		c = (a - 150) / 2 + 50;
	}
	else
		c = a - 100;

	bmi = (b - c) * 100 / c;
	
	if (bmi > (double)20)
	{
		cout << "비만";
	}
	else if (bmi > (double)10)
	{
		cout << "과체중";
	}
	else
		cout << "정상";
}