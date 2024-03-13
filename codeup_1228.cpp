#include <iostream>
using namespace std;

int main()
{
	double a = 0, b = 0, bmi = 0;
	cin >> a >> b;
	// 표준몸무게
	// (a-100)*0.9
	bmi = (b - ((a - 100) * 0.9)) * 100 / ((a - 100) * 0.9);
	
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
