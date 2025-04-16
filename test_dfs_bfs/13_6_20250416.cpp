#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
// 복도의 정보 (최대 사이즈 6)
char board[6][6];
// 선생님 위치 저장용
vector<pair<int, int>> teacher;
// 빈 위치 저장용
vector<pair<int, int>> space;
// 결과 저장용
bool result;

// 4방향에서 학생 판별하는 함수
bool watch(int x, int y, int dir)
{
	if (dir == 0)
	{
		while (y >= 0)
		{
			if (board[x][y] == 'S')
				return true;
			if (board[x][y] == 'O')
				return false;
			y--;
		}
	}
	if (dir == 1)
	{
		while (y < n)
		{
			if (board[x][y] == 'S')
				return true;
			if (board[x][y] == 'O')
				return false;
			y++;
		}
	}
	if (dir == 2)
	{
		while (x >= 0)
		{
			if (board[x][y] == 'S')
				return true;
			if (board[x][y] == 'O')
				return false;
			x--;
		}
	}
	if (dir == 3)
	{
		while (x < n)
		{
			if (board[x][y] == 'S')
				return true;
			if (board[x][y] == 'O')
				return false;
			x++;
		}
	}
	// 가려지지 않은 학생이 있다면
	return false;
}

// 선생님 별 watch 함수 호출
bool process()
{
	for (int i = 0; i < teacher.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// 가려지지 않은 학생이 있다면
			if (watch(teacher[i].first, teacher[i].second, j))
				return true;
		}
	}
	// 학생들이 다 가려졌다면
	return false;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 'T')
				teacher.push_back(make_pair(i, j));
			if (board[i][j] == 'X')
				space.push_back(make_pair(i, j));
		}
	}

	vector<bool> binary(space.size());
	fill(binary.end() - 3, binary.end(), true);
	do
	{
		// 장애물 배치
		for (int i = 0; i < space.size(); i++)
		{
			if (binary[i])
			{
				board[space[i].first][space[i].second] = 'O';
			}
		}
		// 학생들이 다 가려졌다면
		if (!process())
		{
			result = true;
			break;
		}
		// 배치된 장애물 회수
		for (int i = 0; i < space.size(); i++)
		{
			if (binary[i])
			{
				board[space[i].first][space[i].second] = 'X';
			}
		}

	} while (next_permutation(binary.begin(), binary.end()));

	if (result) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}