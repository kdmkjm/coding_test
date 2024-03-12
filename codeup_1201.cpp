#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	if (n > 0)
	{
		cout << "양수";
	}
	else if (n == 0)
	{
		cout << 0;
	}
	else
	{
		cout << "음수";
	}
}