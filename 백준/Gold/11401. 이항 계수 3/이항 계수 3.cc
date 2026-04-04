#include <iostream>

using namespace std;

long long N, K;
const long long MOD = 1000000007;

// 거듭제곱을 분할 정복으로 계산하는 함수
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    if (K == 0 || N == K) {
        cout << 1 << "\n";
        return 0;
    }

    // 1. n! 계산
    long long num = 1;
    for (int i = 2; i <= N; i++) {
        num = (num * i) % MOD;
    }

    // 2. k!(n-k)! 계산
    long long den = 1;
    // k!
    for (int i = 2; i <= K; i++) {
        den = (den * i) % MOD;
    }
    // (n-k)!
    for (int i = 2; i <= N - K; i++) {
        den = (den * i) % MOD;
    }

    // 3. n! * (den ^ (MOD-2)) % MOD 계산
    long long ans = (num * power(den, MOD - 2)) % MOD;

    cout << ans << "\n";

    return 0;
}