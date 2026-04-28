#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<pair<int, bool>> time;
    vector<int> answer;

    for(int i = 0; i < progresses.size(); i++)
    {
        int left = 100 - progresses[i];
        int tmp = (left / speeds[i]) + (left % speeds[i] ? 1 : 0);
        time.push_back({tmp, false});
    }

    for(int i = 0; i < time.size(); i++)
    {
        if(time[i].second == true) continue;
        int pivot = time[i].first;
        int cnt = 0;

        for(int j = i; j < time.size(); j++) 
        {
            if(time[j].first > pivot) break;
            if(time[j].first <= pivot)
            {
                cnt++;
                time[j].second = true;
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}