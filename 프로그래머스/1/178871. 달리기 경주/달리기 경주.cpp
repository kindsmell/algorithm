#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> player_indices;
    for (int i = 0; i < players.size(); i++) {
        player_indices[players[i]] = i;
    }
    
    for (const string& name : callings) {
        int current_idx = player_indices[name];
        int front_idx = current_idx - 1;
        
        string front_name = players[front_idx];
        
        players[front_idx] = name;
        players[current_idx] = front_name;
        
        player_indices[name] = front_idx;
        player_indices[front_name] = current_idx;
    }
    
    return players;
}