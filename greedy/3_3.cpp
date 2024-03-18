/*
숫자 카드 게임은 여러 개의 숫자 카드 중에서 가장 높은 숫자가 쓰인 카드 한 장을 뽑는 게임이다.
단, 게임의 룰을 지키며 카드를 뽑아야 하고 룰은 다음과 같다.
1. 숫자를 쓰인 카드들이 N X M 형태로 놓여있다. 이때 N은 행의 개수를 의미하며, M은 열의 개수를 의미한다.
2. 먼저 뽑고자 하는 카드가 포함되어 있는 행을 선택한다.
3. 그다음 선택된 행에 포함된 카드들 중 가장 숫자가 낮은 카드를 뽑아야 한다.
4. 따라서 처음에 카드를 골라낼 행을 선택할 때, 이후에 해당 행에서 가장 숫자가 낮은 카드를 뽑을 
	것을 고려하여 최종적으로 가장 높은 숫자의 카드를 뽑을 수 있도록 전략을 세워야 한다.

- 입력 조건
첫째 줄에 숫자 카드들이 놓인 행의 개수 N과 열의 개수 M이 공백을 기준으로 각각 자연수로 주어진다 (1 <= N, M <= 100)
둘째 줄부터 N개의 줄에 걸쳐 각 카드에 적힌 숫자가 주어진다. 각 숫자는 1이상 10,000 이하의 자연수이다.

- 출력 조건
첫째 줄에 게임의 룰에 맞게 선택한 카드에 적힌 숫자를 출력한다.

입력예시1
3 3
3 1 2
4 1 4
2 2 2
출력예시1
2
입력예시2
2 4
7 3 1 8
3 3 3 4
출력예시2
3
*/

#include <iostream>
using namespace std;

int n = 0, m = 0, k = 0, result = 10000, ans = 0;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		// 한 행(N)당 최소 값 도출(result)
		result = 10000;

		for (int j = 0; j < m; j++)
		{
			cin >> k;
			if (k < result)
			{
				result = k;
			}
		}

		// 한 행당 최소 값중 최대 값을 결과(ans)에 저장
		if (ans < result)
		{
			ans = result;
		}
	}
	// 결과 출력
	cout << ans;
}