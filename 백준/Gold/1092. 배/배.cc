#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    //전부 내림차순 정렬
    cin >> N;
    vector<int> crane(N);
    for (int i = 0; i < N; i++) cin >> crane[i];
    sort(crane.rbegin(), crane.rend());

    cin >> M;
    vector<int> box(M);
    for (int i = 0; i < M; i++) cin >> box[i];
    sort(box.rbegin(), box.rend());

    if (crane[0] < box[0]) {
        cout << -1 << endl;
        return 0;
    }

    int time = 0;
    // 박스가 다 없어질 때까지 반복
    while (!box.empty()) {
        time++;
        int box_idx = 0;
        for (int i = 0; i < N; i++) {
            // 더 이상 확인할 박스가 없으면 종료
            if (box_idx >= box.size()) break;

            // 현재 크레인이 현재 박스를 들 수 있는지 확인
            while (box_idx < box.size()) {
                if (crane[i] >= box[box_idx]) {
                    box.erase(box.begin() + box_idx); // 박스 제거
                    break; 
                }
                // 못 들면 다음으로 무거운 박스 확인
                box_idx++;
            }
        }
    }

    cout << time << endl;

    return 0;
}