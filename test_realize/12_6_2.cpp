#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool chkPossible(vector<vector<int>> answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        bool check = false;
        int x = answer[i][0];
        int y = answer[i][1];
        int a = answer[i][2];

        // 기둥인 경우
        if (a == 0)
        {
            // 바닥위에 있거나
            if (y == 0)  check = true;

            for (int j = 0; j < answer.size(); j++)
            {
                // 보의 한쪽 끝 부분 위에 있거나
                if (answer[j][0] == x - 1 && answer[j][1] == y && answer[j][2] == 1)
                    check = true;
                if (answer[j][0] == x && answer[j][1] == y && answer[j][2] == 1)
                    check = true;
                // 다른 기둥위에 존재
                if (answer[j][0] == x && answer[j][1] == y - 1 && answer[j][2] == 0)
                    check = true;
            }

            if (!check)  return false;
        }
        // 보인 경우
        else if (a == 1)
        {
            bool left = false, right = false;
            for (int j = 0; j < answer.size(); j++)
            {
                // 한쪽 끝 부분이 기둥 위에 있거나
                if (answer[j][0] == x && answer[j][1] == y - 1 && answer[j][2] == 0)
                    check = true;
                if (answer[j][0] == x + 1 && answer[j][1] == y - 1 && answer[j][2] == 0)
                    check = true;
                // 양쪽 끝부분이 다른 보와 연결
                if (answer[j][0] == x - 1 && answer[j][1] == y && answer[j][2] == 1)
                    left = true;
                if (answer[j][0] == x + 1 && answer[j][1] == y && answer[j][2] == 1)
                    right = true;
            }
            if (left && right)   check = true;
            if (!check)  return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    // 입력정보 건수분 반복
    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];

        // 구조물 설치
        if (b == 1)
        {
            vector<int> tmp_v;
            tmp_v.push_back(x);
            tmp_v.push_back(y);
            tmp_v.push_back(a);

            answer.push_back(tmp_v);   // 일단 설치해봐
            if (!chkPossible(answer))   // 타당성 확인
            {
                answer.pop_back();  // 타당하지 않으면 다시 제거
            }
        }
        // 구조물 해체
        else
        {
            int index = 0;
            // 해당 되는 항목 찾기
            for (int j = 0; j < answer.size(); j++)
            {
                if (x == answer[j][0] && y == answer[j][1] && a == answer[j][2])
                {
                    index = j;
                }
            }
            vector<int> tmp_v;
            tmp_v = answer[index];
            answer.erase(answer.begin() + index);

            if (!chkPossible(answer))   // 타당성 확인
            {
                answer.push_back(tmp_v);  // 타당하지 않으면 다시 추가
            }
        }
    }
    // 오름차순 정렬
    sort(answer.begin(), answer.end());

    return answer;
}