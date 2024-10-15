#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, l;
int map[101][101];
vector<pair<int, char> > v;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int turn(int direction, char c)
{
	if(c == 'L')
	{
		if(direction == 0)	direction = 3;
		else	direction -= 1;
	}
	else
	{
		if(direction == 3)	direction = 0;
		else	direction += 1;
	}
	return direction;
}

int dummy()
{
	int x = 1, y = 1, direction = 0, result = 0, index = 0;
	map[x][y] = 2;
	queue<pair<int, int> > q;
	q.push(make_pair(x,y));

	while(true)
	{
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		if(1 <= nx && 1 <= ny && nx <= n && ny <= n && map[nx][ny] != 2)
		{
			if(map[nx][ny] == 1)
			{
				map[nx][ny] = 2;
				q.push(make_pair(nx,ny));
			}
			else
			{
				int px = q.front().first;
				int py = q.front().second;
				map[px][py] = 0;
				q.pop();
				map[nx][ny] = 2;
				q.push(make_pair(nx,ny));
			}
		}
		else
		{
			result += 1;
			break;
		}

		x = nx;
		y = ny;
		result += 1;

		if(index < l && v[index].first == result)
		{
			direction = turn(direction, v[index].second);
			index += 1;
		}
	}
	return result;
}

int main()
{
	cin >> n;
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	cin >> l;
	for(int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		v.push_back(make_pair(x,c));
	}

	cout << dummy() << '\n';
}