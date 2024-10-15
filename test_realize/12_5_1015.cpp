#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, l;
int map[101][101];
vector<pair<int,char> > v;

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
	int direction = 0;
	int result = 0;
	int x = 1, y = 1;
	int index = 0;
	map[x][y] = 2;	// 뱀이 있을 때 2
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));

	// 종료 규칙에 걸리기 전까지 반복
	while(true)
	{
		// 몸길이를 늘려 머리를 다음칸에 위치시킵니다.
		int nx = x + dx[direction];
		int ny = y + dy[direction];	

		// 종료 규칙 판명
		if(0 < nx && nx <= n && 0 < ny && ny <= n && map[nx][ny] != 2)
		{
			// 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과는 없어지고 꼬리는 움직이지 않습니다.
			if(map[nx][ny] == 1)
			{
				map[nx][ny] = 2;
				q.push(make_pair(nx,ny));
			}
			// 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워줍니다.
			else
			{
				int mx = q.front().first;
				int my = q.front().second;
				q.pop();	// 꼬리 비우기
				map[mx][my] = 0;
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

		if(index < l && result == v[index].first)
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
		map[a][b] = 1;	// 사과 있을 때 1
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