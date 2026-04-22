#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer;
    
    unordered_map<string, int> m;
    
    for(const auto& p:participant) m[p]++;
    
    for(const auto& c:completion) m[c]--;
    
    for(const auto& [name, cnt] : m)
    {
        if(cnt > 0)
        {
            answer = name;
            break;
        }    
    }
    
    return answer;
}