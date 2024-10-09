#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> turn90Degree(vector<vector<int>> x)
{
    // 정사각형이므로 행과 열의 사이즈 동일
    int x_size = x.size();
    vector<vector<int>> tmp_x(x_size, vector<int>(x_size));

    for(int i = 0; i < x_size; i++)
    {
        for(int j = 0; j < x_size; j++)
        {
            tmp_x[j][x_size-i-1] = x[i][j];
        }
    }
    return tmp_x;
}

bool check(vector<vector<int>> newLock)
{
    int m = newLock.size()/3;
    // 자물쇠 값이 전부 1인지 확인 1 아닌게 있다면 false 반환
    for(int i = m; i < 2 * m; i++)
    {
        for(int j = m; j < 2 * m; j++)
        {
            if(newLock[i][j] != 1)
            {
                return false;
            }
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    // 열쇠와 자물쇠의 크기 저장
    int n = key.size();
    int m = lock.size();

    // 자물쇠의 세배 크기의 임의의 이차원 벡터 생성
    // 정확히 (m+n-1)*(m+n-1)크기의 벡터를 생성하면 되지만, 메모리 제한이 충분하기 때문에 그대로 진행
    vector<vector<int>> newLock(3*m, vector<int>(3*m));

    // 새로운 이차원 벡터에 정중앙에 자물쇠 값 입력
    for(int i = m; i < 2 * m; i++)
    {
        for(int j = m; j < 2 * m; j++)
        {
            newLock[i][j] = lock[i-m][j-m];
        }
    }

    // 열쇠는 90도씩 총 4번 회전가능
    for(int R = 0; R < 4; R++)
    {
        key = turn90Degree(key);

        // 범위는 1부터 2 * m - 1 까지
        for(int x = 1; x < 2 * m; x++)
        {
            for(int y = 1; y < 2 * m; y++)
            {
                // 자물쇠에 열쇠 넣기
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        newLock[x + i][y + j] += key[i][j];
                    }
                }
                if(check(newLock))
                {
                    return true;
                }

                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        newLock[x + i][y + j] -= key[i][j];
                    }
                }
            }
        }
    }
    return false;
}