/*
* 순차 탐색
* 생성할 원소 개수를 입력한 다음 한 칸 띄고 찾을 문자열을 입력
* 앞서 적은 원소 개수만큼 문자열을 입력
*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> v;

int main()
{
	int n = 0;
	string name = "";

	cin >> n >> name;
	for (int i = 0; i < n; i++)
	{
		string tmp_name = "";
		cin >> tmp_name;
		v.push_back(tmp_name);
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == name)
		{
			cout << i + 1 << '\n';

			break;
		}
	}
}