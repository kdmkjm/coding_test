// stack 연습
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;

	q.push(5);
	q.push(2);
	q.push(3);
	q.push(7);
	q.pop();

	q.push(1);
	q.push(4);
	q.pop();

	while (!q.empty())
	{
		cout << q.front() << '\n';
		q.pop();
	}
}