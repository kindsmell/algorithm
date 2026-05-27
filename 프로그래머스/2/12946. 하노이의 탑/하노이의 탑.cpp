#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, int mid, vector<vector<int>>& answer) {
    if (n == 1) {
        answer.push_back({from, to});
        return;
    }
    
    // n-1개를 중간 기둥으로 이동
    hanoi(n - 1, from, mid, to, answer);
    
    // 가장 큰 원판을 목적지 기둥으로 이동
    answer.push_back({from, to});
    
    // 중간 기둥에 있던 n-1개를 목적지 기둥으로 이동
    hanoi(n - 1, mid, to, from, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);
    return answer;
}