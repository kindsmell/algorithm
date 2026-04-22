#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> m;
    unordered_map<int, int> cnt_m;
    int goal = nums.size() / 2;
    int result = 0;
    for(const auto& kind : nums) m[kind]++;
    
    int cnt = 0;
    int flag = 0;
    while(1)
    {
        for(auto& [kind, n] : m)
        {
            if(m[kind] > 0)
            {
                
                m[kind]--;
                cnt_m[kind] = 1;
                cnt++;
                if(cnt == goal)
                {
                    flag = 1;
                    break;
                }
            } 
        }
        if(flag == 1) break;
    }
    
    for(const auto& [kind, flag] : cnt_m) result += cnt_m[kind];
        
    return result;
}