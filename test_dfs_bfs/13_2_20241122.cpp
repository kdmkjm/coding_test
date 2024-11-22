#include <iostream>
using namespace std;

int n, m, result;	// 지도의 크기, 결과값
int arr[8][8];		// 원본 지도
int temp[8][8];		// 임의로 기둥 세운뒤의 지도
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int getScore()
{
	int score = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 빈 칸 이라면
			if (temp[i][j] == 0)
			{
				score++;
			}
		}
	}
	return score;
}

void spreadVirus(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		// 사방향 이동 위치 저장
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 유효 범위 내라면
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			// 빈 칸 확인
			if (temp[nx][ny] == 0)
			{
				temp[nx][ny] = 2;
				spreadVirus(nx, ny);
			}
		}
	}
}

void dfs(int count)
{
	// 임의로 세운 기둥이 세개일 경우
	if (count == 3)
	{
		// 임의 지도 설정
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp[i][j] = arr[i][j];
			}
		}
		// 바이러스 확신
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// 임의의 위치가 바어러스라면
				if (temp[i][j] == 2)
				{
					// 바이러스 퍼뜨리기
					spreadVirus(i, j);
				}
			}
		}
		// 바이러스 확산이 끝난 후 안전 영역의 크기 비교후 종료
		result = max(result, getScore());
		return;
	}

	// 기둥 세우기(seems like 조합)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 세우려고 하는 위치가 빈 칸일 경우
			if (arr[i][j] == 0)
			{
				arr[i][j] = 1;		// 기둥세우기
				count++;			// 기둥 갯수 더해주고
				dfs(count);			// 재귀 함수 호출
				count--;			// 반환 후 다시 빼주고
				arr[i][j] = 0;		// 기둥 없애기
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	// 원본 지도 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	// 깊이 우선 탐색 실행
	dfs(0);
	cout << result;
}