#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C;
char lake[1501][1501];
bool swan_visited[1501][1501];
bool water_visited[1501][1501];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pair<int, int>> current_water, tomorrow_water; // 오늘 탐색하는 물인 곳, 탐색하면서 찾은 내일 물이 될 곳
    queue<pair<int, int>> current_swan, tomorrow_swan;   // 오늘 백조1이 갈 수 있는 곳, 내일 백조 1이 탐색해야할 곳
    pair<int, int> dest_swan;

    cin >> R >> C;

    int swan_count = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> lake[i][j];
            if (lake[i][j] != 'X')
            { // 물
                current_water.push({i, j});
                water_visited[i][j] = true;
            }
            if (lake[i][j] == 'L')
            {
                if (swan_count == 0)
                { // 백조 1 위치
                    current_swan.push({i, j});
                    swan_visited[i][j] = true;
                    swan_count++;
                }
                else
                {                       // 백조 2 위치
                    dest_swan = {i, j}; // 목표 백조 위치 저장
                }
            }
        }
    }

    int days = 0;
    while (true)
    {
        // 1. 백조1 움직여본다
        while (!current_swan.empty())
        { // BFS : visited 필요
            pair<int, int> curr = current_swan.front();
            current_swan.pop();

            if (curr.first == dest_swan.first && curr.second == dest_swan.second)
            {
                cout << days << "\n";
                return 0; // 백조1과 백조2가 만났다! -> 목표 달성
            }

            for (int i = 0; i < 4; i++)
            { // 상하좌우 탐색
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];

                if (nr < 0 || nr >= R || nc < 0 || nc >= C || swan_visited[nr][nc])
                    continue; // 탐색하는 좌표가 호수의 좌표범위의 안에 있고 방문하지 않은 곳이어야함

                swan_visited[nr][nc] = true;

                if (lake[nr][nc] == 'X')
                {
                    tomorrow_swan.push({nr, nc}); // 내일은 여기부터!
                }
                else
                {
                    current_swan.push({nr, nc}); // 오늘 더 갈 수 있는 물!
                }
            }
        }

        // 2. 얼음을 녹인다
        while (!current_water.empty())
        {
            pair<int, int> curr = current_water.front();
            current_water.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];

                if (nr < 0 || nr >= R || nc < 0 || nc >= C || water_visited[nr][nc])
                    continue;

                if (lake[nr][nc] == 'X')
                {
                    lake[nr][nc] = '.'; // 녹았다!
                    water_visited[nr][nc] = true;
                    tomorrow_water.push({nr, nc});
                }
            }
        }

        // 3. 내일 준비 (큐 교체)
        current_swan = tomorrow_swan;
        current_water = tomorrow_water;

        // 내일 큐는 비워줘야 함
        while (!tomorrow_swan.empty())
            tomorrow_swan.pop();
        while (!tomorrow_water.empty())
            tomorrow_water.pop();

        days++;
    }
}