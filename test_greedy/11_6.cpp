#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
    // 섭취해야할 음식 없을 시 확인
    long long summary = 0;
    for (int i = 0; i < food_times.size(); i++)
    {
        summary += food_times[i];
    }
    if (summary <= k)
        return -1;

    // 우선 순위큐 생성 1번째항 소요 시간 2번째항 음식 번호
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < food_times.size(); i++)
    {
        // c++ 우선순위큐는 큰 첫번째 항이 우선순위가 높기 때문에 - 값 설정
        pq.push(make_pair(-food_times[i], i + 1));
    }

    summary = 0;            // 먹기 위해 사용한 시간
    long long previous = 0; // 직전에 다 먹은 음식 시간
    long long length = food_times.size();   // 남은 음식의 개수

    while (summary + ((-pq.top().first - previous) * length) <= k)
    {
        int now = -pq.top().first;
        pq.pop();
        summary += (now - previous) * length;
        length--;
        previous = now;
    }

    vector<pair<int, int>> result;
    while (!pq.empty())
    {
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back(make_pair(food_time, num));
    }

    sort(result.begin(), result.end(), compare);
    return result[(k - summary) % length].second;
}