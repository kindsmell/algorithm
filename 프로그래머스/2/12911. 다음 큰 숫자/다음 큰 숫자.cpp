#include <string>

using namespace std;

int getBitCnt(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n & 1) cnt++;
        n >>= 1;
    }
    return cnt;
}

int solution(int n) {
    int baseCnt = getBitCnt(n);
    int num = n + 1;
    
    while (getBitCnt(num) != baseCnt) {
        num++;
    }
    
    return num;
}