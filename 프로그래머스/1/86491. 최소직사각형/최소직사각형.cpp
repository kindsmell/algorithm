#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> sizes) {

    for(auto& v : sizes)     if(v[0] < v[1])  swap(v[0], v[1]);
    
    sort(sizes.begin(), sizes.end());
    int w = sizes.back()[0];
    
    sort(sizes.begin(), sizes.end(), cmp);
    int h = sizes.back()[1];
    
        
    return w * h;
}