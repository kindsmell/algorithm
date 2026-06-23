#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int cnt = 0;
    int end = 0;

    for (int i : section) {
        if (i > end) {
            cnt++;
            end = i + m - 1;
        }
    }

    return cnt;
}