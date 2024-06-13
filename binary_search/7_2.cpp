/*
* 이진 탐색
* 재귀 함수
*/

#include <iostream>
#include <vector>
using namespace std;

int total = 0, target = 0;
vector<int> v;
int b_search(vector<int> v, int target, int start, int end)
{
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	if (v[mid] == target) return mid;
	else if (v[mid] > target) return b_search(v, target, start, mid - 1);
	else if (v[mid] < target) return b_search(v, target, mid + 1, end);
}
int main()
{
	cin >> total >> target;
	for (int i = 0; i < total; i++)
	{
		int n = 0;
		cin >> n;
		v.push_back(n);
	}

	int result = b_search(v, target, 0, total - 1);
	cout << result + 1 << '\n';
}