/*
* 하나의 수열에는 다양한 수가 존재한다. 
* 이러한 수는 크기에 상관없이 나열되어 있다.
* 이 수를 큰 수 부터 작은 수의 순서로 정렬해야 한다.
* 수열을 내림차순으로 정렬하는 프로그램을 만드시오.
* 
* 입력 조건
* 첫째 줄에 수열에 속해 있는 수의 개수 N이 주어진다.(1<=N<=500)
* 둘째 줄부터 N+1번째 줄까지 N개의 수가 입력된다. 
* 수의 범우이는 1이상 100,000 이하의 자연수이다.
* 
* 출력 조건
* 입력으로 주어진 수열이 내림차순으로 정렬된 결과를 공백으로 구분하여 출력
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;

bool compare(int a, int b) {
    return a > b;
}

int main(void) {
    // N을 입력받기
    cin >> n;

    // N개의 정수를 입력받아 리스트에 저장
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // 기본 정렬 라이브러리를 이용하여 내림차순 정렬 수행
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
}