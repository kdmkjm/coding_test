#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i <= 50; i++)
	{
		if (i < 20)
		{
			cout << "hello";
		}
		else if (i == 20)
		{
			cout << " ";
		}
		else
		{
			cout << "world";
		}
	}
}