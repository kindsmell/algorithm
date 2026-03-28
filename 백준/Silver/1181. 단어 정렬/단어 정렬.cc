#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // 1. 정렬 수행
    sort(v.begin(), v.end(), compare);

    // 2. 중복 제거
    v.erase(unique(v.begin(), v.end()), v.end());

    // 3. 출력
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}