#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canInstall(const vector<int>& houses, int C, int dist) {
    int count = 1; // 첫 번째 집에는 무조건 설치
    int last_installed = houses[0];

    for (int i = 1; i < houses.size(); i++) {
        // 현재 집이 마지막 설치 지점으로부터 dist 이상 떨어져 있다면 설치
        if (houses[i] - last_installed >= dist) {
            count++;
            last_installed = houses[i];
        }
    }

    // 설치된 공유기 개수가 목표 C 이상이면 true
    return count >= C;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;
    cin >> N >> C;

    vector<int> houses(N);
    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    // 1. 좌표 정렬 
    sort(houses.begin(), houses.end());

    // 2. 이분 탐색 범위 설정
    int low = 1; 
    int high = houses[N - 1] - houses[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2; // 공유기 사이의 최소 거리 설정

        if (canInstall(houses, C, mid)) {
            // C개 이상 설치 가능하다면, 더 큰 거리를 시도해봄
            result = mid;
            low = mid + 1;
        } else {
            // 설치가 불가능하다면 거리를 좁힘
            high = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}