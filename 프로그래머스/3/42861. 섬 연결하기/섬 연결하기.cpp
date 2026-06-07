#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> parent;

int find(int x){
    if(parent[x] == x)  return x;
    return parent[x] = find(parent[x]);
}

bool unite(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if(rootX != rootY)
    {
        parent[rootY] = rootX;
        return true;
    }
    
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    
    
    for(int i = 0; i < n; i++)  parent.push_back(i);
    
    sort(costs.begin(), costs.end(), [](auto &a, auto &b){
        return a[2] < b[2];
    });
    
    for(int i = 0; i < costs.size(); i++)
    {
        if(unite(costs[i][0], costs[i][1]))
            answer += costs[i][2];
    }
    
    return answer;
}