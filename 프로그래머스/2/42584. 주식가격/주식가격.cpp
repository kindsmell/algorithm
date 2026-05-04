#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); i++)
    {
        int cur = prices[i];
        int cnt  = 0;
        for(int j = i + 1; j < prices.size(); j++)
        {
            cnt++;
            if(cur > prices[j]) break;
        }
        answer.push_back(cnt);
    }
    return answer;
}