// stack 연습
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	// int형 스택 s 생성
	stack<int> s;

	s.push(5);
	s.push(2);
	s.push(3);
	s.push(7);
	s.pop();

	s.push(1);
	s.push(4);
	s.pop();

	while(!s.empty())
	{
		cout << s.top() << '\n';
		s.pop();
	}
}