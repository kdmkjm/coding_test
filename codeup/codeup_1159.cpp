#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	if ((50 <= n && n <= 70) || (n%6==0))
	{
		cout << "win";
	}
	else
	{
		cout << "lose";
	}
}