#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	cout << fixed;
	cout.precision(1);

	cout << ((float)a * b / 2);
}