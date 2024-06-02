// swap
// 0 인덱스와 1인덱스의 원소 교체하기
#include <iostream>
using namespace std;

int main()
{
    int arr[2] = { 3, 5 };
    swap(arr[0], arr[1]);
    cout << arr[0] << " " << arr[1];
}