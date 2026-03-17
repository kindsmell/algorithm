#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M, num;
    unordered_map<int, int> m;

    cin >> N;
    while(N--) {
        cin >> num;
        m[num]++;
    }

    cin >> M;
    while(M--) {
        cin >> num;
        cout << m[num] << " ";
    }
    return 0;
}