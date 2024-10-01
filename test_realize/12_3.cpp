#include <string>
#include <vector>

using namespace std;

int solution(string str) {
    int answer = str.size();
    
    for (int i = 1; i < str.size() / 2 + 1; i++)
    {
    	string compressed = "";
    	string prev = str.substr(0, i);
    	int cnt = 1;
    
    	for (int j = i; j < str.size(); j += i)
    	{
		    if (prev == str.substr(j, i))	cnt += 1;
		    else
		    {
    			if (cnt >= 2)
    			{
    				compressed += to_string(cnt);
    			}
    			compressed += prev;
    
    			prev = str.substr(j, i);
    			cnt = 1;
    		}
    	}
    	if (cnt >= 2)
    	{
    		compressed += to_string(cnt);
	    }
	    compressed += prev;
    
    	answer = min(answer, (int)compressed.size());
    }
    
    return answer;
}