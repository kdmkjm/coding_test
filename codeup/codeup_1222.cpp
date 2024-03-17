#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	int score = 0;
	for (int i = a; a < 90; a += 5)
		score++;

	if (score > (c - b))
	{
		cout << "win";
	}
	else if (score == (c - b))
	{
		cout << "same";
	}
	else
		cout << "lose";
}