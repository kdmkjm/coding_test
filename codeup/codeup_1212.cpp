#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[3] = { 0, };

	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}

	sort(a, a + 3);
	if (a[2] < (a[0] + a[1]))
	{
		cout << "yes";
	}
	else
		cout << "no";
}