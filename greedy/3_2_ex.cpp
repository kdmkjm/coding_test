/*
큰 수의 법칙
배열의 크기 N, 숫자가 더해지는 횟수 M, 그리고 K가 주어질 때 동빈이의 큰 수의 법칙에 따른 결과를 출력하시오.

입력 조건
-첫째 줄에 N(2<=N<=1000), M(1<=M<=10000), K(1<=K<=10000)의 자연수가 주어지며, 각 자연수는 공백으로 구분한다.
-둘째 줄에 N개의 자연수가 주어진다. 각 자연수는 공백으로 구분한다. 단, 각각의 자연수는 1이상 10000이하의 수로
주어진다.
-입력으로 주어지는 K는 항상 M보다 작거나 같다.

출력조건
-첫째 줄에 동빈이의 큰 수의 법칙에 따라 더해진 값을 출력한다.

EX)
입력 예시
5 8 3
2 4 5 4 6

출력 예시
46
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> v;

int main() {
    // N, M, K를 공백을 기준으로 구분하여 입력 받기
    cin >> n >> m >> k;

    // N개의 수를 공백을 기준으로 구분하여 입력 받기
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end()); // 입력 받은 수들 정렬하기
    int first = v[n - 1]; // 가장 큰 수
    int second = v[n - 2]; // 두 번째로 큰 수

    // 가장 큰 수가 더해지는 횟수 계산
    // 한 사이클(첫번째 큰 수 * k + 두번쨰 큰 수)의 총 수 k + 1
    // 총 더해지는 횟수 m을 한 사이클의 총 수로 나눈 몫 * 총 더해지는 수 k
    // = 총 사이클당 수
    // + 사이클이 끝나고 나머지 횟수 ( m % ( k + 1 ) )
    int cnt = (m / (k + 1)) * k;
    cnt += m % (k + 1);

    int result = 0;
    result += cnt * first; // 가장 큰 수 더하기
    result += (m - cnt) * second; // 두 번째로 큰 수 더하기

    cout << result << '\n'; // 최종 답안 출력
}