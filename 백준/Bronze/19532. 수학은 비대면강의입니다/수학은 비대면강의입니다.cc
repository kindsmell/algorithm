#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // x와 y를 모두 -999부터 999까지 확인
    for (int x = -999; x <= 999; x++)
    {
        for (int y = -999; y <= 999; y++)
        {
            // 두 식을 동시에 만족하는지 확인
            if ((a * x + b * y == c) && (d * x + e * y == f))
            {
                cout << x << " " << y << endl;
                return 0;
            }
        }
    }
    return 0;
}