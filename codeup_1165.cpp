#include <iostream>
using namespace std;

int main()
{
	int time = 0, score = 0;
	cin >> time >> score;

	for (time; time < 90; time += 5)
	{
		score++;
	}

	cout << score;
}