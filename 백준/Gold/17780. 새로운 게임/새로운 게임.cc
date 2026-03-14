#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int N, K;
int board[12][12];
vector<int> state[12][12];
int turn = 0;

struct Offset
{
    int dr, dc;
};

Offset directions[] = {
    // 1 : 우 2: 좌 3: 상 4: 하
    {0, 0},
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
};

struct Piece
{
    int name;
    int r, c;    // 현재 위치
    Offset move; // 이동가능한 방향

    void addMoveRule(int input)
    {
        if (input >= 1 && input <= 4)
        {
            move = directions[input];
        }
    }

    pair<int, int> getNextPosition()
    {
        int nr = r + move.dr;
        int nc = c + move.dc;

        return {nr, nc};
    }

    void reverseDirection()
    {
        move.dr *= -1;
        move.dc *= -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    // n줄에 거쳐서 보드판
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    Piece 말[K + 1];
    for (int i = 1; i <= K; i++)
    {
        말[i].name = i;
        int r, c, tmp;
        cin >> r >> c >> tmp;
        말[i].r = r - 1;
        말[i].c = c - 1;
        state[말[i].r][말[i].c].push_back(i);
        말[i].addMoveRule(tmp);
    }

    // 0 : 흰색
    // 1: 빨간색
    // 2: 파란색
    pair<int, int> next;
    int nr, nc;
    while (turn <= 1000)
    {
        turn++;
        for (int i = 1; i <= K; i++)
        {
            int r = 말[i].r;
            int c = 말[i].c;

            // 내가 가장 밑에 있는 말인지 확인
            if (state[r][c][0] != i)
                continue;

            next = 말[i].getNextPosition();
            nr = next.first;
            nc = next.second;

            if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 2)
            {
                말[i].reverseDirection();
                next = 말[i].getNextPosition();
                nr = next.first;
                nc = next.second;
                if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 2)
                    continue;
            }
            if (board[nr][nc] == 0)
            {
                for (int p_idx : state[r][c])
                {
                    말[p_idx].r = nr;
                    말[p_idx].c = nc;               // 좌표 업데이트
                    state[nr][nc].push_back(p_idx); // 새 칸에 쌓기
                }
                state[r][c].clear(); // 원래 칸 비우기
            }
            else if (board[nr][nc] == 1)
            {
                for (int j = state[r][c].size() - 1; j >= 0; j--)
                {
                    int p_idx = state[r][c][j]; // 거꾸로 넣기
                    말[p_idx].r = nr;
                    말[p_idx].c = nc;
                    state[nr][nc].push_back(p_idx);
                }
                state[r][c].clear();
            }

            if (state[nr][nc].size() >= 4)
            {
                cout << turn;
                return 0;
            }
        }
    }

    if (turn > 1000)
        cout << -1;
}