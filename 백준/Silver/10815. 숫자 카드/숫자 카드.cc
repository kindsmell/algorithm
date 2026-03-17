#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    unordered_set<int> s;
    int tmp;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }

    cin >> M;
    int arr[M];
    for (int i = 0; i < M; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < M; i++)
    {
        if (s.find(arr[i]) != s.end())
            cout << "1 ";
        else
            cout << "0 ";
    }
}