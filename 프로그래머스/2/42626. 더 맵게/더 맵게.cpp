#include <string>
#include <queue> ;
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {  
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end()); 
    
    int cnt = 0;
    while(pq.top() < K)
    {
        if(pq.size() < 2) return -1;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        int tmp = first + second * 2;
        pq.push(tmp);
        cnt++;
    }
    return cnt++;
}