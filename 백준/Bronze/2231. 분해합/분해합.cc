#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int result = 0;

    // 각 자릿수의 합이 최대 9 * 6자리를 넘지 않으므로 범위를 최적화할 수 있음!
    for (int i = max(1, N - 54); i < N; i++)
    {
        int sum = i;
        int num = i;

        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        if (sum == N)
        {
            result = i;
            break;
        }
    }

    cout << result << endl;
    return 0;
}