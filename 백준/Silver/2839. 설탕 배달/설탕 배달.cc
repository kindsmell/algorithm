#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;

    while (n >= 0)
    {
        // n이 5로 딱 나누어 떨어지는가
        if (n % 5 == 0)
        {
            cnt += (n / 5);
            cout << cnt << endl;
            return 0;
        }

        // 5로 안 나누어지면 3킬로 봉지 하나를 쓴다
        n -= 3;
        cnt++;
    }

    cout << -1 << endl;
    return 0;
}