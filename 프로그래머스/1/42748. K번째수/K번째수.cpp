#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(const auto& v: commands)
    {
        int start = v[0] - 1;
        int end = v[1];
        int k = v[2] - 1;
        vector<int> arr(array.begin() + start, array.begin() + end);
        
        sort(arr.begin(), arr.end());
        
        answer.push_back(arr[k]);
    }

    return answer;
}