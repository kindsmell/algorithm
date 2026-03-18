#include <iostream>
using namespace std;

int N;
int result;
int tmp;

// 0부터 늘려가면서
// 분해합이 N이 되는지를체크
int main()
{

    cin >> N;
    for (int i = 1; i < N; i++)
    {
        tmp = i;
        int j = i;
        while (j > 0)
        {
            tmp += j % 10;
            j /= 10;
        }

        if (tmp == N)
        {
            result = i;
            break;
        }
    }

    cout << result;
}