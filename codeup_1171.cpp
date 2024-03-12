#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	cout << a;

	if ( b / 10 == 0 )
	{
		cout << 0;
	}
	cout << b;

	// 번호가 세 자릿수인 경우
	if (c / 100 > 0)
	{
		
	}
	// 번호가 두 자릿수인 경우
	else if (c / 10 > 0)
	{
		cout << 0;
	}
	// 번호가 세 자릿수인 경우
	else
	{
		cout << 0 << 0;
	}
	cout << c;
}