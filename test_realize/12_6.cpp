#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m;
vector<vector<int> > build_frame;
vector<int> tmp_frame;
vector<vector<int> > answer;

bool chkPossible(vector<vector<int> > answer)
{
    for(int i = 0; i < answer.size(); i++)
    {
        bool check = false;
        int x = answer[i][0];
        int y = answer[i][1];
        int a = answer[i][2];
        if(a == 0)
        {
            // 바닥 위
            if(y == 0)  check = true;
            // 보의 한 쪽 끝 부분 위 혹은 다른 기둥 위
            for(int j = 0; j < answer.size(); j++)
            {
                if(x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    check = true;
                if(x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    check = true;
                if(x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
            }
            if(!check)  return false;
        }
        else if(a == 1)
        {
            bool check = false;
            bool left = false;
            bool right = false;
            for(int j = 0; j < answer.size(); j++)
            {
                if(x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
                if(x + 1 == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
                if(x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    left = true;
                if(x + 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    right = true;
            }
            if(left && right)   check = true;
            if(!check)  return false;
        }
    }
    return true;
}
int main()
{
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        tmp_frame.clear();
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        tmp_frame.push_back(a);
        tmp_frame.push_back(b);
        tmp_frame.push_back(c);
        tmp_frame.push_back(d);
        build_frame.push_back(tmp_frame);
    }

    tmp_frame.clear();

    for(int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];

        if(b == 1)
        {
            cout << "설치" << '\n';
            tmp_frame.clear();
            tmp_frame.push_back(x);
            tmp_frame.push_back(y);
            tmp_frame.push_back(a);
            answer.push_back(tmp_frame);
            if(!chkPossible(answer))
            {
                answer.pop_back();
            }
        }
        else
        {
            cout << "철거" << '\n';
            tmp_frame.clear();
            int index = 0; 
            for(int j = 0; j < answer.size(); j++)
            { 
                if(x == answer[j][0] && y == answer[j][1] && a == answer[j][2])
                {
                    index = j;
                    tmp_frame = answer[j];
                }
            }
            answer.erase(answer.begin() + index);
            if(!chkPossible(answer))
            {
                answer.push_back(tmp_frame);
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << "[";
    for(int i = 0; i < answer.size(); i++)
    {
        cout << "[";
        for(int j = 0; j < 2; j++)
        {
            cout << answer[i][j] << ",";
        }
        cout << answer[i][2] << "]";
    }
    cout << "]";
}