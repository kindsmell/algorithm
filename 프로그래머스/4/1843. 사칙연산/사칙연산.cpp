#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

vector<char> op;
vector<int> num;
// DP를 위한 메모이제이션 테이블
pair<int, int> memo[105][105];
bool visited[105][105];

pair<int, int> cal(int start, int end) {
    if (start == end) return {num[start], num[start]};
    if (visited[start][end]) return memo[start][end];
    
    int max_val = INT_MIN;
    int min_val = INT_MAX;
        
    for (int k = start; k < end; k++) {
        pair<int, int> left = cal(start, k);
        pair<int, int> right = cal(k + 1, end);
        
        if (op[k] == '+') {
            max_val = max(max_val, left.first + right.first);
            min_val = min(min_val, left.second + right.second);
        } else { 
            max_val = max(max_val, left.first - right.second);
            min_val = min(min_val, left.second - right.first);
        }
    }
    
    visited[start][end] = true;
    return memo[start][end] = {max_val, min_val};
}

int solution(vector<string> arr) {
    op.clear();
    num.clear();
    // visited 배열 초기화
    for(int i=0; i<105; i++) for(int j=0; j<105; j++) visited[i][j] = false;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == "-" || arr[i] == "+")
            op.push_back(arr[i][0]);
        else
            num.push_back(stoi(arr[i]));
    }
    
    return cal(0, num.size() - 1).first;
}