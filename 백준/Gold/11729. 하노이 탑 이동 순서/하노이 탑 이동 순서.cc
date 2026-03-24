#include <iostream>

using namespace std;

void hanoi(int n, int start, int end, int aux) {
    if (n == 1) {
        cout << start << " " << end << "\n";
        return;
    }
    hanoi(n - 1, start, aux, end);
    cout << start << " " << end << "\n";
    hanoi(n - 1, aux, end, start);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 3, 2);
    
    return 0;
}