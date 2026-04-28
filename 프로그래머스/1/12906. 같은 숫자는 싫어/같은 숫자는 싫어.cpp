#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(auto& val : arr)
    {
        if(answer.empty() || answer.back() != val)
            answer.push_back(val);
    }
    return answer;
}