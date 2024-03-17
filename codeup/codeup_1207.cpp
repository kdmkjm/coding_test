#include <iostream>
using namespace std;

int main()
{
	int a[4] = { 0, };
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			cnt++;
		}
	}
	if (cnt == 4)
	{
		cout << "윷";
	}
	else if (cnt == 3)
	{
		cout << "걸";
	}
	else if (cnt == 2)
	{
		cout << "개";
	}
	else if (cnt == 1)
	{
		cout << "도";
	}
	else
	{
		cout << "모";
	}
}