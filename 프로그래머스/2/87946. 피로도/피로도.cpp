#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    sort(dungeons.begin(), dungeons.end());
    
    do {
        int current_k = k;
        int count = 0;
        
        for (const auto& dungeon : dungeons) {
            if (current_k >= dungeon[0]) {
                current_k -= dungeon[1];
                count++;
            } else {
                break;
            }
        }
        
        answer = max(answer, count);
        
    } while (next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}