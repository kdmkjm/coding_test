/*
큰 수의 법칙
배열의 크기 N, 숫자가 더해지는 횟수 M, 그리고 K가 주어질 때 동빈이의 큰 수의 법칙에 따른 결과를 출력하시오.

입력 조건
-첫째 줄에 N(2<=N<=1000), M(1<=M<=10000), K(1<=K<=10000)의 자연수가 주어지며, 각 자연수는 공백으로 구분한다.
-둘째 줄에 N개의 자연수가 주어진다. 각 자연수는 공백으로 구분한다. 단, 각각의 자연수는 1이상 10000이하의 수로 
주어진다.
-입력으로 주어지는 K는 항상 M보다 작거나 같다.

출력조건
-첫째 줄에 동빈이의 큰 수의 법칙에 따라 더해진 값을 출력한다.

EX) 
입력 예시
5 8 3
2 4 5 4 6

출력 예시
46
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int i, int j)
{
	return j < i;
}

int main()
{
	int N = 0, M = 0, K = 0, result = 0, cnt = 0;

	cin >> N >> M >> K;

	int arr[1000] = { 0, };

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	// 내림차순 정렬
	sort(arr, arr + N, compare);
	while (M > 0)
	{
		if (cnt == K)
		{
			result += arr[1];
			cnt = 0;
		}
		else
		{
			result += arr[0];
			cnt++;
		}
		M--;
	}

	cout << result;
}