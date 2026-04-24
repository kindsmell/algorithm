#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s(phone_book.begin(), phone_book.end());
    
    for(const auto& num : phone_book)
    {
        string prefix = "";
        for(int i = 0; i < num.size() - 1; i++)
        {
            prefix += num[i];
            
            if(s.count(prefix)) return false;
        }
    }
    
    return true;
}