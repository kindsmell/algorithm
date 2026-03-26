#include <iostream>
#include <vector>

using namespace std;

// 최대 범위 설정
const int MAX = 1000000;
bool is_prime[MAX + 1];

void sieve() {
    // 모든 수를 소수로 초기화
    fill(is_prime, is_prime + MAX + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(); // 소수 배열 미리 만들기

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int count = 0;
        // a + b = N 일 때, a <= b 조건을 만족하기 위해 i는 N/2까지만 검사
        for (int i = 2; i <= N / 2; i++) {
            if (is_prime[i] && is_prime[N - i]) {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}