#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> origin(N);    // 원본 순서 유지용
    vector<int> sorted_v(N);  // 정렬 및 중복 제거용

    for (int i = 0; i < N; i++) {
        cin >> origin[i];
        sorted_v[i] = origin[i];
    }

    // 1. 정렬
    sort(sorted_v.begin(), sorted_v.end());

    // 2. 중복 제거
    sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());

    // 3. 이분 탐색으로 인덱스 찾기
    for (int i = 0; i < N; i++) {
        // lower_bound는 찾고자 하는 값 이상의 숫자가 처음 나타나는 위치를 반환
        auto it = lower_bound(sorted_v.begin(), sorted_v.end(), origin[i]);
        
        // 해당 위치의 반복자에서 시작 반복자를 빼면 -> 곧 '인덱스'이자 '나보다 작은 수의 개수'
        cout << distance(sorted_v.begin(), it) << " ";
    }

    return 0;
}