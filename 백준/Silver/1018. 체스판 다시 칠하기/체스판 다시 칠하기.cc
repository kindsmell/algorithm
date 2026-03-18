#include <iostream>
#include <algorithm> // min 함수 사용
#include <string>
using namespace std;

int main()
{
    int N, M;
    char board[51][51];

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int min_result = 64;

    // 8x8로 자를 수 있는 시작점
    for (int row = 0; row <= N - 8; row++)
    {
        for (int col = 0; col <= M - 8; col++)
        {

            int countW = 0;

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    char correctColor;
                    // (i + j) 합이 짝수면 시작색과 같아야 함
                    if ((i + j) % 2 == 0)
                        correctColor = 'W';
                    else
                        correctColor = 'B';

                    if (board[row + i][col + j] != correctColor)
                    {
                        countW++;
                    }
                }
            }
            int current_min = min(countW, 64 - countW);

            // 전체 판 중에서 가장 작은 값 업데이트
            if (current_min < min_result)
            {
                min_result = current_min;
            }
        }
    }

    cout << min_result << endl;
    return 0;
}