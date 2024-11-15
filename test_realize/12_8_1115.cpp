#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    int length = weak.size();
    for(int i = 0; i < length; i++)
    {
        weak.push_back(weak[i] + n);
    }
    answer = dist.size() + 1;

    for(int start = 0; start < length; start++)
    {
        int cnt = 1;
        int position = weak[start] + dist[cnt - 1];
        do
        {
            int cnt = 1;
            int position = weak[start] + dist[cnt - 1];
            for(int index = start; index < start + length; index++)
            {
                if(position < weak[index])
                {
                    cnt++;
                    position = weak[index] + dist[cnt - 1];
                }
            }
            answer = min(cnt, answer);
        } while (next_permutation(dist.begin(), dist.end()));
    }

    if(answer > dist.size())
    {
        return -1;
    }
    return answer;
}