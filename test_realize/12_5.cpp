#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, l;
int arr[101][101];
vector<pair<int, char> > info;

// 오른쪽 아래쪽 왼쪽 위쪽
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int turn(int direction, char c)
{
    if(c == 'L')
    {
        if(direction == 0)
        {
            direction = 3;
        }
        else
            direction -= 1;
    }
    else
    {
        if(direction == 3)
        {
            direction = 0;
        }
        else
            direction += 1;
    }
    return direction;
}

int simulate()
{
    // 시작점 저장
    int x = 1, y = 1;
    arr[x][y] = 2;
    int direction = 0;
    int time = 0;
    int index = 0;
    queue<pair<int,int> > q;
    q.push(make_pair(x, y));

    while(true)
    {
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if( nx <= n && ny <= n && 1 <= nx && 1 <= ny && arr[nx][ny] != 2)
        {
            // 이동 지점에 사과가 존재하는 경우
            if(arr[nx][ny] == 1)
            {
                arr[nx][ny] = 2;
                q.push(make_pair(nx,ny));
            }
            // 이동 지점에 사과가 존재하지 않는 경우
            else if(arr[nx][ny] == 0)
            {
                arr[nx][ny] = 2;
                int px = q.front().first;
                int py = q.front().second;
                q.pop();
                q.push(make_pair(nx,ny));
                arr[px][py] = 0;
            }
        }
        else
        {
            time += 1;
            break;
        }

        x = nx;
        y = ny;
        time += 1;
         if (index < l && time == info[index].first) 
         {
            direction = turn(direction, info[index].second);
            index += 1;
        }
    }
    return time;
}

int main()
{
    // 보드의 크기
    cin >> n;

    // 사과의 개수
    cin >> k;

    // 사과의 위치
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    // 방향 변환 횟수
    cin >> l;

    for(int i = 0; i < l; i++)
    {
        int tmp_i;
        char tmp_c;
        cin >> tmp_i >> tmp_c;
        info.push_back(make_pair(tmp_i, tmp_c));
    }

    cout << simulate() << '\n';
}