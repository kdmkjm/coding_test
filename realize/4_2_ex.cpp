/*
00시 00분 00초 부터 N시 59분 59초까지의 모든 시간 중에 3이 하나라도 포함되는
모든 경우의 수를 구하는 프로그램을 작성하시오.

- 입력 조건
첫째 줄에 정수 N이 입력된다.(0<=N<=23)

- 출력 조건
모든 경우의 수를 출력한다.

입력예시
5
출력예시
11475
*/

#include <iostream>
using namespace std;

int h, cnt;

// 특정한 시각 안에 '3'이 포함되어 있는지의 여부
bool check(int h, int m, int s) {
    if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
        return true;
    return false;
}

int main(void) {
    // H를 입력받기 
    cin >> h;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                // 매 시각 안에 '3'이 포함되어 있다면 카운트 증가
                if (check(i, j, k)) cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
