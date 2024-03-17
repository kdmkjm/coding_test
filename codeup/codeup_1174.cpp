#include <iostream>
using namespace std;

int main()
{
	int h = 0, m = 0;
	cin >> h >> m;

	h += 24;
	m = m + h * 60;
	m -= 30;
	h = m / 60;
	h = h % 24;
	m = m % 60;

	cout << h << " " << m;
}