#include <iostream>
#include <vector>

using namespace std;

char board[2200][2200];

void print_blank(int n, int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            board[x + i][y + j] = ' ';
    }
}

void print_star(int n, int x, int y)
{
    if (n == 1)
    {
        board[x][y] = '*';
        return;
    }

    int size = n / 3;

    // 이전 모양 별을 3번 그림
    print_star(size, x, y);
    print_star(size, x, y + size);
    print_star(size, x, y + 2 * size);

    // 별 + 공백 + 별
    print_star(size, x + size, y);
    print_blank(size, x + size, y + size);
    print_star(size, x + size, y + 2 * size);

    // 별 3번
    print_star(size, x + 2 * size, y);
    print_star(size, x + 2 * size, y + size);
    print_star(size, x + 2 * size, y + 2 * size);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            board[i][j] = ' ';
    }

    print_star(n, 0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}