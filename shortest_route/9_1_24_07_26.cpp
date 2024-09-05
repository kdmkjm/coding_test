#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

// 노드 개수 n, 간선 개수 m, 시작 지점 start
int n, m, start;
// 코스트 입력 받을 벡터
vector<pair<int, int> > v[100001];
// 최단 거리를 저장할 정수형 배열
int d[100001];
// 방문 여부를 판단할 논리형 배열
bool visited[100001];

// 인접한 노드 중 가장 코스트가 적은 노드를 찾아 해당 노드의 인덱스 반환
int getSmallestNode(void)
{
	int index = 0;
	int min_v = INF;

	// 노드 수 만큼 반복
	for (int i = 1; i <= n; i++)
	{
		// 코스트가 최소 코스트 보다 작으면서 방문하지 않은 노드
		if (d[i] < min_v && !visited[i])
		{
			// 최소 코스트 갱신
			min_v = d[i];

			// 해당 노드의 인덱스 저장
			index = i;
		}
	}
	return index;
}

void dijkstra(int start)
{
	// 시작 지점 방문 처리
	d[start] = 0;
	visited[start] = true;

	// 시작 지점 부터 이어진 간선에 대한 정보 최단 거리 배열에 저장
	for (int i = 0; i < v[start].size(); i++)
	{
		d[v[start][i].first] = v[start][i].second;
	}

	// 시작 노드 제외 남은 노드 수만큼 반복
	for (int i = 1; i < n; i++)
	{
		// 시작 노드에서 가장 코스트가 적은 노드찾는 함수 호출
		int now = getSmallestNode();
		// 해당 노드 방문 처리
		visited[now] = true;

		// now 노드와 연결된 다른 노드 확인
		for (int j = 0; j < v[now].size(); j++)
		{
			// now 노드와 연결 된 노드
			// 최단 거리 비교 : 최단 거리 배열에 들어있는 코스트 vs now 노드를 거쳐서 가는 코스트
			int cost = d[now] + v[now][j].second;
			if (d[v[now][j].first] > cost)
			{
				d[v[now][j].first] = cost;
			}
		}
	}
}

int main()
{
	// n, m 입력 받기
	cin >> n >> m;
	// start 입력 받기
	cin >> start;

	// 코스트 입력 받기
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}

	// 최단 거리 배열 전 항목 초기화
	fill_n(d, 100001, INF);

	// 다익스트라 알고리즘 함수 호출
	dijkstra(start);

	// 결과 출력부
	// 노드의 개수만큼 반복
	for (int i = 1; i <= n; i++)
	{
		// 최단 거리 배열이 초기치 INF 라면
		if (d[i] == INF) cout << i << "번 째 노드는 도달할 수 없는 노드입니다." << '\n';
		else cout << i << "번 째 노드의 최단 거리는 " << d[i] << "입니다." << '\n';
	}
}