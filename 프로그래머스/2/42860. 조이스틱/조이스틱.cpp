#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int cnt = 0;
    
    vector<int> v;
    
    for(int i = 0; i < name.size(); i++)
    {
        int val1 = name[i] - 'A';
        int val2 = 'Z' - name[i] + 1;
        int diff = min(val1, val2);
        v.push_back(diff);
        cnt += diff;
        
    }
    
    int min_move = name.length() - 1; 

    for(int i = 0; i < name.length(); i++) {
        int next_i = i + 1;
        while(next_i < name.length() && name[next_i] == 'A') {
            next_i++;
        } // next_i는 뭉치의 마지막 A의 바로 다음 인덱스

        int case1 = (i * 2) + name.length() - next_i; 
        int case2 = (name.length() - next_i) * 2 + i; 
        
        min_move = min({min_move, case1, case2}); 
        
        i = next_i - 1;
    }
    
    cnt += min_move;
    return cnt;
}