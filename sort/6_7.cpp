#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };

	sort(arr, arr + 10);

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << '\n';
	}
}