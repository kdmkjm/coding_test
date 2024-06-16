/*
* 1로 만들기
*/
#include <iostream>
using namespace std;

int result[30001];
int x;

int main()
{
	cin >> x;

	for (int i = 2; i < x + 1; i++)
	{
		// 초기화 상태이기 때문에 임시 값으로 -1 값을 설정
		result[i] = result[i - 1] + 1;
		if (result[i] % 5 == 0) result[i] = min(result[i], result[i / 5] + 1);
		if (result[i] % 3 == 0) result[i] = min(result[i], result[i / 3] + 1);
		if (result[i] % 2 == 0) result[i] = min(result[i], result[i / 2] + 1);
	}

	cout << result[x] << '\n';
}