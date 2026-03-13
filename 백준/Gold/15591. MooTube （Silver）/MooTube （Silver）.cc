#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q;
int p, q, r;
int k, v;
int result = 0;
vector<pair<int, int>> adj[5001]; // 인접리스트
bool visited[5001];

void dfs(int v)
{
    visited[v] = 1; // 방문 표시

    for (auto &next_node : adj[v])
    {
        int next_v = next_node.first;
        int weight = next_node.second;

        if (!visited[next_v] && weight >= k)
        {
            dfs(next_v);
            result++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> p >> q >> r;
        adj[p].push_back({q, r});
        adj[q].push_back({p, r});
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> k >> v;
        result = 0;
        fill(visited, visited + N + 1, false);
        dfs(v);
        cout << result << "\n";
    }
}