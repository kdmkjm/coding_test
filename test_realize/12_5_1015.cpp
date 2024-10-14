#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, l;
int map[101][101];
vector<pair<int, char>> v;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int turn(int direction, char c)
{
	if (c != 'L')
	{
		if (direction == 3)
			direction = 0;
		else
			direction += 1;
	}
	else
	{
		if (direction == 0)
			direction = 3;
		else
			direction -= 1;
	}
	return direction;
}

int simulate()
{
	int direction = 0;	// 오른쪽 이동
	map[1][1] = 2;		// 뱀이 존재할 경우 2(시작점)
	int result = 0;		// 실행시간
	int x = 1, y = 1;	// 시작점
	queue<pair<int, int>> q;	// 뱀의 상태 나타내는 큐
	q.push(make_pair(x, y));
	int index = 0;		// 몇 초째의 방향 전환 정보를 참조해야되는지 값

	while (true)
	{
		// 뱀 이동 후 좌표
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		// 벽 또는 자기 자신과 몸을 부딪히면 게임 끝
		if (0 < nx && nx <= n && 0 < ny && ny <= n && map[nx][ny] != 2)
		{
			// 게임이 종료 조건에 만족하지 않는다면
			// 이동한 칸에 사과가 있다면 사과 없애고 꼬리 움직이지 않음
			if (map[nx][ny] == 1)
			{
				map[nx][ny] = 2;
			}
			// 사과가 없다면 꼬리칸 비우기
			else
			{
				map[nx][ny] = 2;
				int px = q.front().first;
				int py = q.front().second;
				q.pop();
				map[px][py] = 0;
			}

			// 이동한 칸을 큐에 넣어주기
			q.push(make_pair(nx, ny));
		}
		else
		{
			result += 1;
			break;
		}

		x = nx;
		y = ny;
		result += 1;
		if (index < l && result == v[index].first)
		{
			direction = turn(direction, v[index].second);
			index += 1;
		}
	}
	return result;
}

int main()
{
	cin >> n;	// 보드의 크기
	cin >> k;	// 사과의 개수
	for (int i = 0; i < k; i++)	// 사과의 위치 입력
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;	// 사과가 존재할 때 1
	}
	cin >> l;	// 반환 변환 정보
	for (int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		v.push_back(make_pair(x, c));
	}

	cout << simulate() << '\n';
}