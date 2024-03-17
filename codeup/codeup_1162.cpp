#include <iostream>
using namespace std;

int main()
{
	int year = 0, mon = 0, day = 0;
	cin >> year >> mon >> day;

	if ((year - mon + day) % 10 == 0)
	{
		cout << "대박";
	}
	else
	{
		cout << "그럭저럭";
	}
}