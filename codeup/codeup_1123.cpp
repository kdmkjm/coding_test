#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	cout << fixed;
	cout.precision(3);

	cout << (float)9 / 5 * n + 32;
}