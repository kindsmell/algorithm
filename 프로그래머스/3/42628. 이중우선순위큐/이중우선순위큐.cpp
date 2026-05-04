#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> arr; 
    
    for(int i = 0; i < operations.size(); i++) {
        char op = operations[i][0];
        int num = stoi(operations[i].substr(2));
        
        if(op == 'I') {
            arr.push_back(num);
            sort(arr.begin(), arr.end());
        } 
        else if (!arr.empty()) { 
            if(num == 1) {
                arr.pop_back(); // 최댓값 삭제
            } else if(num == -1) {
                arr.erase(arr.begin()); // 최솟값 삭제
            }
        }
    }
    
  
    if(arr.empty()) {
        return {0, 0};
    } else {
        return {arr.back(), arr.front()};
    }
}