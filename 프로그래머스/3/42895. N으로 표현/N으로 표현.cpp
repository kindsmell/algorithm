#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int solution(int N, int number) {
    vector<set<int>> dp(9);

    for (int i = 1; i <= 8; i++) {
        string s = "";
        for (int k = 0; k < i; k++) s += to_string(N);
        dp[i].insert(stoi(s));

        for (int j = 1; j <= i / 2; j++) {
            for (int op1 : dp[j]) {
                for (int op2 : dp[i - j]) {
                    dp[i].insert(op1 + op2);
                    dp[i].insert(op1 - op2);
                    dp[i].insert(op2 - op1);
                    dp[i].insert(op1 * op2);
                    if (op2 != 0) dp[i].insert(op1 / op2);
                    if (op1 != 0) dp[i].insert(op2 / op1);
                }
            }
        }

        if (dp[i].count(number)) return i;
    }

    return -1;
}