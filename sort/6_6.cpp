// 계수 정렬
#include <iostream>
using namespace std;

int a[15] = { 7,5,9,0,3,1,6,2,9,1,4,8,0,5,2 };
int chk[10] = { 0, };

int main()
{
	for (int i = 0; i < 15; i++)
	{
		chk[a[i]]++;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < chk[i]; j++)
			cout << i << " ";
	}
}