#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

int N;
ll B;

// 두 행렬을 곱하는 함수
matrix multiply(matrix &A, matrix &B) {
    matrix res(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res[i][j] += (A[i][k] * B[k][j]);
            }
            res[i][j] %= 1000; // 결과값을 1000으로 나눈 나머지 저장
        }
    }
    return res;
}

// 행렬을 B번 거듭제곱하는 함수 (분할 정복)
matrix power(matrix A, ll b) {
    if (b == 1) return A;

    matrix half = power(A, b / 2);
    matrix res = multiply(half, half);

    if (b % 2 == 1) {
        res = multiply(res, A);
    }
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> B;

    matrix origin(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> origin[i][j];
            origin[i][j] %= 1000; // 입력 단계에서 미리 나머지 연산 (B=1인 경우 대비)
        }
    }

    matrix result = power(origin, B);

    // 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}