#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Virus {
public:
	int index;
	int second;
	int x;
	int y;
	Virus(int index, int second, int x, int y)
	{
		this->index = index;
		this->second = second;
		this->x = x;
		this->y = y;
	}
	bool operator<(Virus& other)
	{
		return this->index < other.index;
	}
};

int n, k;
int graph[200][200];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
vector<Virus> viruses;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
			// 해당 위치가 바이러스 라면
			if (graph[i][j] != 0)
			{
				viruses.push_back(Virus(graph[i][j], 0, i, j));
			}
		}
	}

	sort(viruses.begin(), viruses.end());
	queue<Virus> q;
	for (int i = 0; i < viruses.size(); i++)
	{
		q.push(viruses[i]);
	}
	
	int t_s, t_x, t_y;
	cin >> t_s >> t_x >> t_y;
	while (!q.empty())
	{
		Virus virus = q.front();
		q.pop();
		if (virus.second == t_s)	break;
		for (int i = 0; i < 4; i++)
		{
			int nx = virus.x + dx[i];
			int ny = virus.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (graph[nx][ny] == 0)
				{
					graph[nx][ny] = virus.index;
					q.push(Virus(graph[nx][ny], virus.second + 1, nx, ny));
				}
			}
		}
	}
	cout << graph[t_x-1][t_y-1] << '\n';
}