#include <iostream>
using namespace std;

int main()
{
	int bmi = 0;
	cin >> bmi;
	if (bmi > 20)
	{
		cout << "비만";
	}
	else if (bmi > 10)
	{
		cout << "과체중";
	}
	else
		cout << "정상";
}