#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    unordered_map<char, int> min_press;

    for (const string& keys : keymap) {
        for (int i = 0; i < keys.length(); ++i) {
            char c = keys[i];
            int press = i + 1;
            if (min_press.find(c) == min_press.end() || min_press[c] > press) {
                min_press[c] = press;
            }
        }
    }

    vector<int> answer;
    for (const string& target : targets) {
        int total = 0;
        bool possible = true;
        for (char c : target) {
            if (min_press.find(c) == min_press.end()) {
                possible = false;
                break;
            }
            total += min_press[c];
        }
        
        if (possible) {
            answer.push_back(total);
        } else {
            answer.push_back(-1);
        }
    }

    return answer;
}