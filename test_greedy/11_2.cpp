#include <iostream>
using namespace std;

string s;

int main()
{
	cin >> s;
	long long result = s[0] - '0';

	for (int i = 1; i < s.length(); i++)
	{
		int tmp = s[i] - '0';
		cout << "tmp " << tmp << '\n';
		if ((tmp == 0 || tmp == 1) || result == 0)
		{
			result += tmp;
		}
		else
		{
			result *= tmp;
		}
	}

	cout << result << '\n';
}