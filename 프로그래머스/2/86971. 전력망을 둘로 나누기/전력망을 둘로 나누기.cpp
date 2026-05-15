#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int dfs(int node, int parent, int ignore_u, int ignore_v, const vector<vector<int>>& adj) {
    int count = 1;
    for (int next : adj[node]) {
        if (next == parent) continue;
        if ((node == ignore_u && next == ignore_v) || (node == ignore_v && next == ignore_u)) continue;
        count += dfs(next, node, ignore_u, ignore_v, adj);
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    vector<vector<int>> adj(n + 1);
    
    for (const auto& w : wires) {
        adj[w[0]].push_back(w[1]);
        adj[w[1]].push_back(w[0]);
    }
    
    for (const auto& w : wires) {
        int count = dfs(1, 0, w[0], w[1], adj);
        answer = min(answer, abs(n - 2 * count));
    }
    
    return answer;
}