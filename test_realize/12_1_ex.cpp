#include <iostream>
using namespace std;

string s;
int sum;

int main()
{
	cin >> s;
    // size함수의 시간 복잡도
    // O(1)

    // length함수의 시간 복잡도
    // O(n)
	for (int i = 0; i < s.size() / 2; i++)
	{
		sum += s[i] - '0';
	}

	for (int i = s.size() / 2; i < s.size(); i++)
	{
		sum -= s[i] - '0';
	}

	if (sum == 0)
	{
		cout << "LUCKY" << '\n';
	}
	else
		cout << "READY" << '\n';
}