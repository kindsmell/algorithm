#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    vector<pair<char, int>> v;
    for(int i = 0; i < number.length(); i++)
    {
        v.push_back({number[i], i});
    }
    
    // 만들어야하는 자리 수
    int target = number.length() - k;
    
    int start = 0;
    // 목표가 6자리 수이면 6번 반복하면 됨
    for(int i = 0; i < target; i++) {
        int end = k + i;
        
        // 정렬 대신 가장 큰 요소만 찾음: O(M)
        auto max = max_element(number.begin() + start, number.begin() + end + 1);
        
        answer += *max;
        start = (max - number.begin()) + 1;
    }
    
    return answer;
}