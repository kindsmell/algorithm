#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1]) return a[1] > b[1]; // 소요시간 짧은 순
        if (a[0] != b[0]) return a[0] > b[0]; // 요청시각 빠른 순
        return a[2] > b[2];                   // 작업번호 작은 순
    }
};


int solution(vector<vector<int>> jobs) {
    
    // [요청 시각, 소요시간, 작업번호]
    for(int i = 0; i < jobs.size(); i++) jobs[i].push_back(i);
    sort(jobs.begin(), jobs.end()); // 요청 시각 기준으로 정렬. 오름차순.
    
    int time = 0;
    int sum = 0;
    int cnt = 0;
    int idx = 0;
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    
    while(cnt < jobs.size())
    {
        for(; idx < jobs.size(); idx++)
        {
            if(jobs[idx][0] > time) break;
            pq.push(jobs[idx]);
        }
        
        if(!pq.empty())
        {
            vector<int> cur = pq.top();
            pq.pop();
            time += cur[1];
            sum += (time - cur[0]);
            cnt++;
        }
        else{
            time = jobs[idx][0];
        }
    }
    
    return sum / jobs.size();
}
