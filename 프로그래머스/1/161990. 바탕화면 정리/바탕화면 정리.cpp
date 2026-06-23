#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int min_row = 51, min_col = 51;
    int max_row = -1, max_col = -1;

    for (int row = 0; row < wallpaper.size(); ++row) {
        for (int col = 0; col < wallpaper[row].size(); ++col) {
            if (wallpaper[row][col] == '#') {
                min_row = min(min_row, row);
                min_col = min(min_col, col);
                max_row = max(max_row, row + 1);
                max_col = max(max_col, col + 1);
            }
        }
    }

    return {min_row, min_col, max_row, max_col};
}