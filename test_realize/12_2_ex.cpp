#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<char> v;
int sum;

int main()
{
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
        // use isalpha method
		if (isalpha(s[i]))
			v.push_back(s[i]);
		else
			sum += s[i] - '0';
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << sum << '\n';
}