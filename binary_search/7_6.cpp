/*
* 부품 찾기 - 계수 정렬
*/
#include <iostream>
using namespace std;

int n, m;
int arr[1000001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		arr[x]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x = 0;
		cin >> x;
		if (arr[x] == 0) cout << "no ";
		else cout << "yes ";
	}
}