#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int map[105][105] = {0,};
    for(auto& p : puddles) map[p[1]][p[0]] = -1;

    long long dp[105][105] = {0,};
    
    dp[1][1] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(map[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if(i == 1 && j == 1) continue;

            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    
    return dp[n][m];
}