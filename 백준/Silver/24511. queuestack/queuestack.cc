#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> type(N);
    for (int i = 0; i < N; i++) {
        cin >> type[i];
    }

    deque<int> dq;
    for (int i = 0; i < N; i++) {
        int initial_value;
        cin >> initial_value;
        
        if (type[i] == 0) {
            dq.push_back(initial_value);
        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int next_value;
        cin >> next_value;
        dq.push_front(next_value);
        cout << dq.back() << " ";
        dq.pop_back();
    }

    return 0;
}