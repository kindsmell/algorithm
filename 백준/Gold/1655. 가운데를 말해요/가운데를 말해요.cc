#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int tmp;
    priority_queue<int> max_pq;                            // 최대힙, 작은 수를 모으기
    priority_queue<int, vector<int>, greater<int>> min_pq; // 최소 힙, 큰 수를 모으기

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        // 개수 유지하면서 넣기
        if (max_pq.size() > min_pq.size())
        {
            min_pq.push(tmp);
        }
        else
            max_pq.push(tmp);

        if (!min_pq.empty() && (max_pq.top() >= min_pq.top()))
        {
            // swap. max_pq.top() < min_pq.top()을 유지하도록
            int tmp1 = max_pq.top();
            int tmp2 = min_pq.top();

            max_pq.pop();
            min_pq.pop();

            max_pq.push(tmp2);
            min_pq.push(tmp1);
        }

        cout << max_pq.top() << "\n";
    }

    return 0;
}