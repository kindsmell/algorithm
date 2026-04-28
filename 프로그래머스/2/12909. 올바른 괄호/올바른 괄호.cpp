#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> tmp;
    for(const auto& val : s)
    {
        if(val == '(') tmp.push(val);
        else
        {
            if(tmp.empty()) return false;
            tmp.pop();
        }
    }

    return tmp.empty();
}