#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, l;
    cin >> n >> w >> l;

    int tmp;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        q.push(tmp);
    }

    int curr_w = 0; // 현재 도로 위에 있는 차들의 무게
    int time = 0;   // 시간
    int curr_car;
    queue<pair<int, int>> bridge;         // 무게, 넣을때의 시간
    while (!q.empty() || !bridge.empty()) // 큐가 전부 비고, 모두 다 건넌게 확실해질 때까지
    {
        time++;
        // bridge에 올라있는 트럭 관리. w시간만큼만 살아잇을수있다.
        // 들어갈때의 시간이랑 현재 시간이랑 비교하자
        if (!bridge.empty() && (time - bridge.front().second >= w))
        {
            curr_w -= bridge.front().first;
            bridge.pop();
        }

        // 최대 개수 체크
        if (bridge.size() >= w)
            continue;

        if (!q.empty())
        {
            curr_car = q.front();
            if (curr_w + curr_car > l) // 최대 무게 체크
                continue;

            // 들어감. 들어갈때 bridge 큐에 넣기
            bridge.push({curr_car, time});
            curr_w += curr_car;
            q.pop();
        }
    }

    cout << time;
}