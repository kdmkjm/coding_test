/*
여행 계획서가 주어졌을 떄 여행가 A가 최종적으로 도착할 지점의 좌표를 출력하는 프로그램을 작성하시오.

- 입력 조건
첫째 줄에 공간의 크기를 나타내는 N이 주어진다.(1<=N<=100)
둘째 줄에 여행가 A가 이동할 계획서 내용이 주어진다.(1<=이동 횟수<=100)

- 출력 조건
첫째 줄에 여행가 A가 최종적으로 도착할 지점의 좌표(X,Y)를 공백으로 구분하여 출력한다.

입력예시
5
R R R U D D
출력예시
3 4
*/

#include <iostream>
#include <string>
using namespace std;

// 변수 선언
int n;
string plans;
int x = 1, y = 1;
char plan;

// L, R, U, D에 따른 이동방향
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int moveTypes[4] = { 'L', 'R', 'U', 'D' };

int main(void)
{
	cin >> n;
	cin.ignore();
	getline(cin, plans);

	for (int i = 0; i < plans.size(); i++)
	{
		plan = plans[i];

		// 이동 후 좌표 구하기
		int nx = -1, ny = -1;
		for (int j = 0; j < 4; j++)
		{
			if (plan == moveTypes[j])
			{
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}

		if (nx < 1 || ny < 1 || nx > n || ny > n)
		{
			continue;
		}

		x = nx;
		y = ny;
	}
	cout << x << ' ' << y;
}