#include <iostream>
using namespace std;

string s;

int main()
{
	cin >> s;

	int area_0 = 0, area_1 = 0;
	int tmp = s[0] - '0';
	if (tmp == 1)
		area_1++;
	else
		area_0++;

	for (int i = 1; i < s.length(); i++)
	{
		int num = s[i] - '0';
		if (tmp == num)
		{
			continue;
		}
		else
		{
			if (num == 1)
			{
				area_1++;
				tmp = num;
			}
			else
			{
				area_0++;
				tmp = num;
			}
		}
	}

	cout << min(area_0, area_1) << '\n';
}