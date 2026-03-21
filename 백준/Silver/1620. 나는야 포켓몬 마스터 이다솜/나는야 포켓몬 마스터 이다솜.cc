#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 이름으로 번호를 찾기 위한 map
    map<string, int> name_to_num;
    // 번호로 이름을 찾기 위한 vector (인덱스 활용)
    vector<string> num_to_name(n + 1);

    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        name_to_num[name] = i;
        num_to_name[i] = name;
    }

    for (int i = 0; i < m; i++) {
        string query;
        cin >> query;

        // 입력의 첫 글자가 숫자인지 확인
        if (isdigit(query[0])) {
            int num = stoi(query);
            cout << num_to_name[num] << "\n";
        } else {
            cout << name_to_num[query] << "\n";
        }
    }

    return 0;
}