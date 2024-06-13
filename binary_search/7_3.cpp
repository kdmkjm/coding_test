/*
* 이진 탐색
* 반복문
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	int total = 0, target = 0, start = 0, mid = 0, end = 0;
	cin >> total >> target;

	for (int i = 0; i < total; i++)
	{
		int n = 0;
		cin >> n;
		v.push_back(n);
	}
	end = total - 1;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (v[mid] == target) break;
		else if (v[mid] > target) {
			end = mid - 1;
		}
		else if (v[mid] < target){
			start = mid + 1;
		}
	}
	cout << mid + 1 << '\n';
}