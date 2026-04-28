#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    vector<int> answer;

    for(int i = 0; i < progresses.size(); i++) {
        int left = 100 - progresses[i];
        int days = (left + speeds[i] - 1) / speeds[i];
        q.push(days);
    }

    while(!q.empty()) {
        int pivot = q.front(); 
        q.pop();
        int cnt = 1;

        while(!q.empty() && q.front() <= pivot) {
            cnt++;
            q.pop();
        }
        
        answer.push_back(cnt);
    }

    return answer;
}