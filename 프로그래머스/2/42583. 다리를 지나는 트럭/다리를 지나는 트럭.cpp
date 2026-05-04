#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {


    int t = 0;
    int cur_w = 0;
    int idx = 0;;
    queue<int> q;
    
    
    for(int i = 0; i < bridge_length; i++)
        q.push(0);
    
    while(idx < truck_weights.size())
    {
        t++;
        
        cur_w -= q.front();
        q.pop();
        
        int next_w = truck_weights[idx];
        
        if( cur_w + next_w <= weight)
        {
            q.push(next_w);
            cur_w += next_w;
            idx++;
        }
        else
            q.push(0);
    }
    
    return  t + bridge_length;
}