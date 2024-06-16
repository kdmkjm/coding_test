/*
* 바닥 공사
*/
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> result;

int main()
{
	cin >> n;
	// 0번째
	result.push_back(0);
	// 1번째
	result.push_back(1);
	// 2번째
	result.push_back(3);

	for (int i = 3; i <= n; i++)
	{
		int tmp = 0;
		tmp = ((result[i - 1] + result[i - 2] * 2) % 796796);
		result.push_back(tmp);
	}

	cout << result.at(n) << '\n';
}