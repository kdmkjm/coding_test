#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Virus
{
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
vector<Virus> viruses;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main()
{
	cin >> n >> k;
	// 시험관의 정보 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
			// 해당 위치가 바이러스 라면
			if (graph[i][j] != 0)
			{
				// 벡터에 삽입
				viruses.push_back(Virus(graph[i][j], 0, i, j));
			}
		}
	}

	// s x y 입력
	int t_s, t_x, t_y;
	cin >> t_s >> t_x >> t_y;

	sort(viruses.begin(), viruses.end());
	queue<Virus> q;
	for (int i = 0; i < viruses.size(); i++)
	{
		q.push(viruses[i]);
	}

	while (!q.empty())
	{
		// 처음 큐에 들어있는 항목 뽑아내고
		Virus now = q.front();
		// 버리기
		q.pop();
		// 만약 해당 되는 초라면
		if (now.second == t_s)
			break;	// 반복 종료

		for (int i = 0; i < 4; i++)
		{
			// 첫 항목으로 부터 움직일 수 있는 좌표 뽑아내고
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			// 시험관 범위 내에 존재할 경우
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				// 만약 바이러스가 존재하지 않을 경우
				if (graph[nx][ny] == 0)
				{
					// 해당 바이러스 감염
					graph[nx][ny] = now.index;
					// 큐에 넣어주기
					q.push(Virus(graph[nx][ny], now.second + 1, nx, ny));
				}
			}
		}
	}	// 큐가 빌 떄 까지 반복

	cout << graph[t_x - 1][t_y - 1] << '\n';
}