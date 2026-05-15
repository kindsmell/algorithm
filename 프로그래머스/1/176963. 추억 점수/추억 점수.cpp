#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> score_map;
    
    for (int i = 0; i < name.size(); i++) {
        score_map[name[i]] = yearning[i];
    }
    
    for (const auto& p : photo) {
        int sum = 0;
        for (const string& person : p) {
            if (score_map.find(person) != score_map.end()) {
                sum += score_map[person];
            }
        }
        answer.push_back(sum);
    }
    
    return answer;
}