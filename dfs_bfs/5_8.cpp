// DFS
// DFS 구현
#include <iostream>
#include <vector>
using namespace std;

vector<int> g[9];
bool visited[9];

void dfs(int n)
{
	// 방문한 곳을 true 로 치환
	visited[n] = true;
	cout << n << " ";

	for (int i = 0; i < g[n].size(); i++)
	{
		int m = g[n][i];

		if (visited[m] == false)
		{
			dfs(m);
		}
	}
}

int main()
{
	// 그래프 정보 리스트 자료형 구현
	g[1].push_back(2);
	g[1].push_back(3);
	g[1].push_back(8);

	g[2].push_back(1);
	g[2].push_back(7);

	g[3].push_back(1);
	g[3].push_back(4);
	g[3].push_back(5);

	g[4].push_back(3);
	g[4].push_back(5);

	g[5].push_back(3);
	g[5].push_back(4);

	g[6].push_back(7);

	g[7].push_back(2);
	g[7].push_back(6);
	g[7].push_back(8);

	g[8].push_back(1);
	g[8].push_back(7);

	dfs(1);
}