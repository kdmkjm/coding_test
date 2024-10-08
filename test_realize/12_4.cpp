#include <iostream>
#include <vector>
using namespace std;

// 2차원 배열 90도 회전
vector<vector<int> > trun90Degree(vector<vector<int>> a)
{
	int n = a.size();

	vector<vector<int> > result(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[j][n - i - 1] = a[i][j];
		}
	}
	return result;
}

// 정답 확인
bool check(vector<vector<int>> newLock)
{
	int lockLength = newLock.size() / 3;

	for (int i = lockLength; i < lockLength * 2; i++)
	{
		for (int j = lockLength; j < lockLength * 2; j++)
		{
			if (newLock[i][j] != 1)
				return false;
		}
	}
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	int n = lock.size();
	int m = key.size();

	vector<vector<int>> newLock(n * 3, vector<int>(n * 3));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			newLock[i + n][j + n] = lock[i][j];
		}
	}

	for (int rota = 0; rota < 4; rota++)
	{
		key = trun90Degree(key);
		for (int x = 0; x < n * 2; x++)
		{
			for (int y = 0; y < n * 2; y++)
			{
				// 자물쇠에 열쇠 넣기
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < m; j++)
					{
						newLock[x + i][y + j] += key[i][j];
					}
				}
				if (check(newLock)) return true;

				// 자물쇠에 열쇠 넣기
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < m; j++)
					{
						newLock[x + i][y + j] -= key[i][j];
					}
				}
			}
		}
	}
	return false;
}