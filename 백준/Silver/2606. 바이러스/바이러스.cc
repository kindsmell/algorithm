#include <iostream>
#include <vector>

using namespace std;


vector<int> adj[101];
bool visited[101];    // 방문 여부 체크
int cnt = 0;          // 감염된 컴퓨터 수

void dfs(int current) {
    visited[current] = true; // 현재 컴퓨터 방문 처리

    for (int next : adj[current]) {
        if (!visited[next]) {
            cnt++;           // 새로 감염된 컴퓨터 카운트
            dfs(next);       // 재귀적으로 탐색
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; 
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1번 컴퓨터부터 탐색 시작
    dfs(1);

    cout << cnt << "\n";

    return 0;
}