#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for (long long x = 0; x <= d; x += k) {
        long long max_y_sq = (long long)d * d - x * x;
        long long max_y = sqrt(max_y_sq);
        
        answer += (max_y / k) + 1;
    }
    
    return answer;
}