/*
거스름돈
당신은 음식점의 게산을 도와주는 점원이다. 카운터에는 거스름돈으로 사용할 500원, 100원, 50원, 10원짜리 동전이
무한히 존재한다고 가정한다. 손님에게 거슬러 줘야 할 돈이 N원일 때 거슬러 줘야 할 동전의 최소 개수를 구해라
단, 거슬러 줘야 할 돈 N은 항상 10의 배수이다.
*/

#include <iostream>
using namespace std;

int main()
{
	int n = 0, total = 0;
	cin >> n;

	// 동전 타입별로 정수형 배열 생성/
	int type[4] = { 500, 100, 50, 10 };

	for (int i = 0; i < 4; i++)
	{
		total += (n / type[i]);
		n %= type[i];
	}

	cout << total;
}