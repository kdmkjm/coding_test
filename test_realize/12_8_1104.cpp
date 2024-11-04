#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
	int length = weak.size();
	// 원형 형태의 외벽을 길이 2배짜리 직선 외벽으로 변경
	for (int i = 0; i < length; i++)
	{
		weak.push_back(weak[i] + n);
	}

	// 정답을 담을 변수 초기화(최대 인원수 + 1)
	int answer = dist.size() + 1;

	// 두배한 외벽 길이만큼 반복
	for (int start = 0; start < length; start++)
	{
		do {
			int cnt = 1;
			// 첫번째 취약지점부터의 도착 거리 산출
			int position = weak[start] + dist[cnt - 1];

			// 본 외벽의 길이만큼 반복
			for (int index = start; index < start + length; index++)
			{
				// 첫번째 친구가 다 보수하지 못한 경우
				if (position < weak[index])
				{
					// 두번째 친구가 보수시작
					cnt++;
					// 만약 최대 친구수를 넘었을 경우
					if (cnt > dist.size())
					{
						break;
					}
					position = weak[index] + dist[cnt - 1];
				}
			}
			// 최솟값 도출
			answer = min(answer, cnt);
		} while (next_permutation(dist.begin(), dist.end()));
	}
	// 현재 인원으로 모든 취약지점 보수가 안될 때
	if (answer > dist.size())
	{
		return -1;
	}
	return answer;
}