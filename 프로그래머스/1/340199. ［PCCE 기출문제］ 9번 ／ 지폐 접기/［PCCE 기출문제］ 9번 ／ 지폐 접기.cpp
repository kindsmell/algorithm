#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int w_min = min(wallet[0], wallet[1]);
    int w_max = max(wallet[0], wallet[1]);
    
    int b_min = min(bill[0], bill[1]);
    int b_max = max(bill[0], bill[1]);
    
    while (b_min > w_min || b_max > w_max) {
        if (b_min > b_max) {
            b_min /= 2;
        } else {
            b_max /= 2;
        }
        
        if (b_min > b_max) {
            swap(b_min, b_max);
        }
        
        answer++;
    }
    
    return answer;
}