/*
* N명의 학생 정보가 있다. 학생 정보는 학생의 이름과 성적으로 구분된다.
* 성적이 낮은 순서대로 학생의 이름을 출력하는 프로그램을 작성하시오
* 
* 입력 조건
* 첫번째 줄에 학생의 수 N이 입력
* 두번째 줄부터 학생의 이름 성적이 주어진다.
* 
* 출력 조건
* 모든 학생의 이름을 성적이 낮은 순서대로 출력하라
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<string, int>> stu;

bool comp(pair<string, int> a, pair<string, int> b)
{
	return a.second < b.second;
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name = "";
		int score = 0;

		cin >> name >> score;
		stu.push_back(make_pair(name, score));
	}

	sort(stu.begin(), stu.end(), comp);

	for (int i = 0; i < n; i++)
	{
		cout << stu[i].first << " ";
	}
}