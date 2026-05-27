#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    int num;
    vector<int> nums;
    
    while (ss >> num) {
        nums.push_back(num);
    }
    
    auto min_max = minmax_element(nums.begin(), nums.end());
    
    return to_string(*min_max.first) + " " + to_string(*min_max.second);
}