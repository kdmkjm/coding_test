#include <iostream>
using namespace std;

int cnt = 0;
void recursive_function(int cnt)
{
	if (cnt > 100)
	{
		return;
	}

	cout << cnt << "번째 재귀함수가 호출되었습니다." << '\n';
	cnt++;
	recursive_function(cnt);
}

int main()
{
	recursive_function(cnt);
}