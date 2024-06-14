/*
* 부품 찾기 - 이진 탐색
* stl 미사용편
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string b_search(vector<int> st, int start, int end, int target)
{
	if (start > end) return "no";

	int mid = (start + end) / 2;
	if (st[mid] == target) return "yes";
	else if (st[mid] < target) return b_search(st, mid + 1, end, target);
	else if (st[mid] > target) return b_search(st, start, mid - 1, target);
}

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
		
		cout << b_search(st, 0, n - 1, x) << " ";
	}
}