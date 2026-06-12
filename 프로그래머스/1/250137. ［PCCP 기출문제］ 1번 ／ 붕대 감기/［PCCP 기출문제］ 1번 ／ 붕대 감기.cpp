#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    
    int max_health = health;
    int current_health = health;
    int success_count = 0;
    int attack_idx = 0;
    int last_time = attacks.back()[0];
    
    for (int time = 1; time <= last_time; ++time) {
        if (time == attacks[attack_idx][0]) {
            current_health -= attacks[attack_idx][1];
            success_count = 0;
            attack_idx++;
            
            if (current_health <= 0) return -1;
        } else {
            current_health += x;
            success_count++;
            
            if (success_count == t) {
                current_health += y;
                success_count = 0;
            }
            
            if (current_health > max_health) {
                current_health = max_health;
            }
        }
    }
    
    return current_health;
}