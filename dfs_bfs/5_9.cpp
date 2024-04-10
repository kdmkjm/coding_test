// BFS
// BFS 구현
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[9];
bool visited[9];

void bfs(int n)
{
	queue<int> q;
	q.push(n);

	// 탐색 시작 노드를 큐에 삽입하고 방문 처리를 한다
	visited[n] = true;

	// 큐에서 해당 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은
	// 노드를 모두 삽입 후 방문 처리를 한다.
	while (!q.empty())
	{
		// 탐색 완료한 노드를 꺼내기
		int x = q.front();
		cout << x << '\n';
		q.pop();
		
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];

			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main()
{
	v[1].push_back(2);
	v[1].push_back(3);
	v[1].push_back(8);

	v[2].push_back(1);
	v[2].push_back(7);

	v[3].push_back(1);
	v[3].push_back(4);
	v[3].push_back(5);

	v[4].push_back(3);
	v[4].push_back(5);

	v[5].push_back(3);
	v[5].push_back(4);

	v[6].push_back(7);

	v[7].push_back(2);
	v[7].push_back(6);
	v[7].push_back(8);

	v[8].push_back(1);
	v[8].push_back(7);

	bfs(1);
}