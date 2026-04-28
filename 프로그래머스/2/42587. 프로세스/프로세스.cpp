#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    priority_queue<int> pq;

    for (int val : priorities)
        pq.push(val);

    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
        q.push({priorities[i], i});

    pair<int, int> tmp;
    int cnt = 0;
    while (1)
    {
        tmp = q.front();
        if (tmp.first < pq.top())
        {
            q.pop();
            q.push(tmp);
        }
        else
        {
            cnt++;
            if(tmp.second == location) return cnt;
            pq.pop();
            q.pop();
        }
    }
}