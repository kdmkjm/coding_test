/*
체스판( 8 X 8 )이 존재한다. 체스판위 특정한 한 칸에 나이트가 서 있다.
나이트는 L자 형태로만 이동할 수 있다.
수평으로 두 칸 이동한 뒤에 수직으로 한칸
수직으로 두 칸 이동한 뒤에 수평으로 한칸

- 입력 조건
첫째 줄에 8 X 8 좌표 평면상에서 현재 나이트가 위치한 곳의 좌표를 나타내는 두 문자로 구성된 문자열이 입력된다.
입력 문자는 a1처럼 열과 행으로 이뤄진다.

- 출력 조건
첫째 줄에 나이트가 이동할 수 있는 경우의 수를 출력한다.

입력예시
a1
출력예시
2
*/

#include <iostream>
using namespace std;

string inputData;

// 나이트가 이동할 수 있는 8가지 방향 정의
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main(void) {
    // 현재 나이트의 위치 입력받기(String)
    cin >> inputData;

    // 행을 입력받기(정수형)
    int row = inputData[1] - '0';
    // 열을 입력받기(문자열에서 바로 정수형으로 변경)
    int column = inputData[0] - 'a' + 1;

    // 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
    int result = 0;
    for (int i = 0; i < 8; i++) {
        // 이동하고자 하는 위치 확인(매 반복마다 초기치 부터의 값을 계산하기 위해 루프 안에 선언 및 초기화)
        int nextRow = row + dx[i];
        int nextColumn = column + dy[i];
        // 해당 위치로 이동이 가능하다면 카운트 증가
        if (nextRow >= 1 && nextRow <= 8 && nextColumn >= 1 && nextColumn <= 8) {
            result += 1;
        }
    }

    cout << result << '\n';
    return 0;
}
