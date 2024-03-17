#include <iostream>
using namespace std;

int main()
{
	int lot[7] = { 0, };
	int sco[6] = { 0, };
	int cnt = 0, bon = 0;
	for (int i = 0; i < 7; i++)
	{
		cin >> lot[i];
	}
	for (int i = 0; i < 6; i++)
	{
		cin >> sco[i];
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (lot[j] == sco[i])
			{
				cnt++;
			}
		}
		if (sco[i] == lot[6])
		{
			bon++;
		}
	}
	
	if (cnt == 6)
	{
		cout << 1;
	}
	else if (cnt == 5)
	{
		if (bon == 1)
		{
			cout << 2;
		}
		else
			cout << 3;
	}
	else if (cnt == 4)
	{
		cout << 4;
	}
	else if (cnt == 3)
	{
		cout << 5;
	}
	else
		cout << 0;
}