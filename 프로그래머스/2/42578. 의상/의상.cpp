#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    unordered_map<string, int> m;
    
    for(int i = 0; i < clothes.size(); i++) m[clothes[i][1]]++;
    
    int result = 1;
    for(const auto& [type, cnt] : m)
    {
        result *= (cnt + 1);
    }
    
    return result -1;
    
}