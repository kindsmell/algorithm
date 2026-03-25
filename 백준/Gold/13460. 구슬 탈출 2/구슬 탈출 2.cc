#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct State {
    int rx, ry, bx, by, depth;
};

int N, M;
char board[11][11];
bool visited[11][11][11][11];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void move(int &x, int &y, int &cnt, int dr, int dc) {
    cnt = 0;
    while (board[x + dr][y + dc] != '#' && board[x][y] != 'O') {
        x += dr;
        y += dc;
        cnt++;
    }
}

int solve(int srx, int sry, int sbx, int sby) {
    queue<State> q;
    q.push({srx, sry, sbx, sby, 0});
    visited[srx][sry][sbx][sby] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.depth >= 10) break;

        for (int i = 0; i < 4; i++) {
            int nrx = cur.rx, nry = cur.ry, nbx = cur.bx, nby = cur.by;
            int rc, bc;

            move(nrx, nry, rc, dx[i], dy[i]);
            move(nbx, nby, bc, dx[i], dy[i]);

            if (board[nbx][nby] == 'O') continue;
            if (board[nrx][nry] == 'O') return cur.depth + 1;

            if (nrx == nbx && nry == nby) {
                if (rc > bc) { nrx -= dx[i]; nry -= dy[i]; }
                else { nbx -= dx[i]; nby -= dy[i]; }
            }

            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, cur.depth + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int srx, sry, sbx, sby;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') { srx = i; sry = j; }
            else if (board[i][j] == 'B') { sbx = i; sby = j; }
        }
    }

    cout << solve(srx, sry, sbx, sby) << "\n";

    return 0;
}