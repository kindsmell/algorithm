#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;

    queue<int> q;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        q.push(tmp);
    }

    stack<int> s;
    int complete = 0;
    while (!q.empty())
    {
        // 스택, 꺼낼 수 있을 만큼 다 꺼내야함
        while (!s.empty() && s.top() == complete + 1)
        {
            s.pop();
            complete++;
        }
        // 큐
        if (q.front() == complete + 1)
        {
            q.pop();
            complete++;
        }
        else
        {
            int tmp = q.front();
            q.pop();
            s.push(tmp);
        }
    }

    // 큐가 끝났는데 스택에 쌓여있을 경우
    while (!s.empty())
    {
        if (s.top() == complete + 1)
        {
            s.pop();
            complete++;
        }
        else
            break;
    }

    if (complete == N)
        cout << "Nice";
    else
        cout << "Sad";
}