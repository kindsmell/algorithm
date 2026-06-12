#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int ans = 0;
    
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        int num = i;
        
        // n이 되는지 확인
        while (sum < n) {
            sum += num;
            num++;
        }
        
        if (sum == n) {
            ans++;
        }
    }
    
    return ans;
}