#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> d;

	d.push_front(3);	// 3
	d.push_front(5);	// 5 3
	d.push_back(9);		// 5 3 9

	d.insert(d.begin() + 1, 7);	// 5 7 3 9

	// 덱의 사이즈 4
	cout << d.size() << '\n';

	d.push_front(1);	// 1 5 7 3 9
	d.pop_back();		// 1 5 7 3
	d.pop_front();		// 5 7 3

	d.erase(d.begin() + 2);		// 5 7

	// 덱이 비어있는지 확인
//	while (!d.empty())
//	{
//		cout << d.front() << " ";
//		d.pop_front();
//	}

	// index로 접근 가능
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}

	d.clear();
}