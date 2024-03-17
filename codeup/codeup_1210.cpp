#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> menu;
	menu.insert(make_pair(1, 400));
	menu.insert(make_pair(2, 340));
	menu.insert(make_pair(3, 170));
	menu.insert(make_pair(4, 100));
	menu.insert(make_pair(5, 70));

	int a = 0, b = 0;
	cin >> a >> b;

	if (menu[a] + menu[b] > 500)
	{
		cout << "angry";
	}
	else
		cout << "no angry";
}