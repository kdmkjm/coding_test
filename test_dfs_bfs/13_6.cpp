#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char board[6][6];
vector<pair<int, int>> teachers;
vector<pair<int, int>> spaces;
bool found;

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
	return false;
}

bool process()
{
	for (int i = 0; i < teachers.size(); i++)
	{
		int x = teachers[i].first;
		int y = teachers[i].second;
		for (int i = 0; i < 4; i++)
		{
			if (watch(x, y, i))
			{
				return true;
			}
		}
	}
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
			{
				teachers.push_back(make_pair(i, j));
			}
			if (board[i][j] == 'X')
			{
				spaces.push_back(make_pair(i, j));
			}
		}
	}

	// spaces에서 3개를 뽑는 조합 확인
	vector<bool> binary(spaces.size());
	fill(binary.end() - 3, binary.end(), true);
	do
	{
		for (int i = 0; i < spaces.size(); i++)
		{
			if (binary[i])
			{
				int x = spaces[i].first;
				int y = spaces[i].second;
				board[x][y] = 'O';
			}
		}
		if (!process())
		{
			found = true;
			break;
		}

		for (int i = 0; i < spaces.size(); i++)
		{
			if (binary[i])
			{
				int x = spaces[i].first;
				int y = spaces[i].second;
				board[x][y] = 'X';
			}
		}
	} while (next_permutation(binary.begin(), binary.end()));

	if (found) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}