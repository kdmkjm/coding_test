#include <iostream>
using namespace std;

int main()
{
	int h = 0, m = 0;
	cin >> h >> m;

	m -= 30;
	if (m < 0)
	{
		h--;
		if (h < 0)
		{
			h = 23;
		}
		m += 60;
	}

	cout << h << " " << m;
}