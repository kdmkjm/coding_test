// 삽입 정렬
#include <iostream>
using namespace std;

int a[10] = {7,5,9,0,3,1,6,2,4,8};

int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
			}
            else
            {
                break;
            }
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << '\n';
	}
}