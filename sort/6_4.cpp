// 퀵 정렬
#include <iostream>
using namespace std;

int a[10] = { 5,7,9,0,3,1,6,2,4,8 };

void quick_sort(int* a, int start, int end)
{
	if (start >= end)
		return;
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while (left <= end && a[left] <= a[pivot])
			left++;
		while (right > start && a[right] >= a[pivot])
			right--;
		// 엇갈렸다면 작은 데이터와 피벗 변경
		if (left > right)
		{
			swap(a[pivot], a[right]);
		}
		// 엇갈리지 않았다면 왼쪽과 오른쪽 변경
		else
			swap(a[left], a[right]);
	}
	quick_sort(a, start, right - 1);
	quick_sort(a, right + 1, end);
}

int main()
{
	quick_sort(a, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << '\n';
	}
}