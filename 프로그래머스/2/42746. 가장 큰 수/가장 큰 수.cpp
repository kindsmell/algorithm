#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> str;
    for(const auto& n : numbers)    str.push_back(to_string(n));
    
    sort(str.begin(), str.end(), [](auto& a, auto& b){
        return a + b > b + a;
    });
    
    if (str[0] == "0") return "0";
    
    for(const auto& s : str)
    {
        answer += s;
    }
    
    
    return answer;
}