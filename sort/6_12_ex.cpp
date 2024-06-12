/*
* 배열 A, B가 주어졌을때
* 주어진 수만큼 원소를 바꿔치기 하여 가능한 최댓값을 만들자
*
* 입력 조건
* 첫 번째 줄에 N,K가 공백으로 구분되어 입력된다.
* 두 번째 줄에 배열 A의 원소들이 입력
* 세 번째 줄에 배열 B의 원소들이 입력
*
* 출력 조건
* 최대 K번의 바꿔치기 연산을 수행하여 만들 수 있는 배열 A의 모든 원소의
* 합의 최댓값을 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> a, b;

bool compare(int x, int y) {
	return x > y;
}

int main(void)
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	for (int i = 0; i < k; i++)
	{
		if (a[i] < b[i]) swap(a[i], b[i]);
		else break;
	}

	long long result = 0;
	for (int i = 0; i < n; i++)
	{
		result += a[i];
	}
	cout << result << '\n';
}