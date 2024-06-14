/*
* 부품 찾기 - 이진 탐색
* stl 사용편
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> st;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		st.push_back(x);
	}

	sort(st.begin(), st.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x = 0;
		cin >> x;
		// algorithm header에 정의되어있는 함수 반환값은 bool타입
		if (binary_search(st.begin(), st.end(), x) == true)
		{
			cout << "yes" << ' ';
		}
		else cout << "no" << ' ';
	}
}