#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int cur = -30001;
    sort(routes.begin(), routes.end(), [](auto& a, auto& b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    
    
    for(int i = 0; i < routes.size(); i++)
    {
        if(routes[i][0] > cur) 
        {
            cur = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}