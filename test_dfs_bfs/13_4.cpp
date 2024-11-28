#include <string>
#include <vector>

using namespace std;

int splitString(string p)
{
    int cnt = 0;
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i] == '(') cnt++;
        else    cnt--;
        if(cnt == 0)    return i;
    }
    return -1;
}

bool chkString(string p)
{
    int cnt = 0;
    if(p[0] != '(') return false;
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i] == '(') cnt++;
        else    cnt--;
        if(cnt == 0 && p[i] == ')') return true;    
    }
    return false;
}

string solution(string p) {
    string answer = "";
    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if(p == "") return answer;
    // 2.문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 
    // 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
    int index = splitString(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);
    // 3.문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
    if(chkString(u))
    {
        // 3-1.수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
        answer = u;
        answer += solution(v);
        return answer;
    }
    // 4.문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
    else
    {
        // 4-1.빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        answer = "(";
        // 4-2.문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
        answer += solution(v);
        // 4-3.')'를 다시 붙입니다.
        answer += ")";
        // 4-4.u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        u = u.substr(1, u.size() - 2);
        for(int i = 0; i < u.size(); i++)
        {
            if(u[i] == '(') u[i] = ')';
            else    u[i] = '(';
        }
        // 4-5.생성된 문자열을 반환합니다.
        answer += u;
    }
    return answer;
}