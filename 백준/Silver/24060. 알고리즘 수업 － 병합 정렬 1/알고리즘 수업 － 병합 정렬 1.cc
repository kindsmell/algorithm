#include <iostream>
#include <vector>
using namespace std;

int n, k;
int cnt = 0;

void merge(vector<int> &A, int p, int q, int r)
{
    int i = p;     // 왼쪽 시작
    int j = q + 1; // 오른쪽 시작
    int t = 0;     // 인덱스
    vector<int> tmp(r - p + 1);

    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }
    while (i <= q)
        tmp[t++] = A[i++];
    while (j <= r)
        tmp[t++] = A[j++];
    i = p;
    t = 0;
    while (i <= r)
    {
        cnt++;
        if (cnt == k)
        {
            cout << tmp[t];
            return;
        }
        A[i++] = tmp[t++];
    }
}

void merge_sort(vector<int> &A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    cin >> n >> k;

    vector<int> A(n);

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        A[i] = tmp;
    }

    merge_sort(A, 0, n - 1);
    if (cnt < k)
        cout << -1;
}