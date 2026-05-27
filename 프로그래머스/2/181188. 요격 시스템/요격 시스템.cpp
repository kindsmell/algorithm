#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int answer = 0;
    int last_pos = -1;

    for (const auto& target : targets) {
        if (target[0] >= last_pos) {
            answer++;
            last_pos = target[1];
        }
    }

    return answer;
}