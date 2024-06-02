#include <iostream>
using namespace std;

int n = 10;
int a[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };
int main()
{
	int min_index = 0, tmp_num = 0;

	for (int i = 0; i < n; i++)
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min_index] > a[j])
			{
				min_index = j;
			}
		}

		tmp_num = a[i];
		a[i] = a[min_index];
		a[min_index] = tmp_num;

		cout << a[i] << '\n';
	}
}