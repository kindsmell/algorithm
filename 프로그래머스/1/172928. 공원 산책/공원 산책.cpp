#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int H = park.size();
    int W = park[0].size();
    int r, c;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (park[i][j] == 'S') {
                r = i;
                c = j;
            }
        }
    }

    for (const string& route : routes) {
        char op = route[0];
        int dist = route[2] - '0';
        int nr = r, nc = c;
        bool possible = true;

        for (int i = 0; i < dist; ++i) {
            if (op == 'N') nr--;
            else if (op == 'S') nr++;
            else if (op == 'W') nc--;
            else if (op == 'E') nc++;

            if (nr < 0 || nr >= H || nc < 0 || nc >= W || park[nr][nc] == 'X') {
                possible = false;
                break;
            }
        }

        if (possible) {
            r = nr;
            c = nc;
        }
    }

    return {r, c};
}