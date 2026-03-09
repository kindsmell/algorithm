#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int dp[100001] = {0};

    int w, v;

    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        for (int j = k; j >= w; j--)
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[k];
}
