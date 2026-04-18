#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    // 내 위치 찾기 (층, 열)
    int my_f = (num - 1) / w + 1;
    int my_c = (my_f % 2 != 0) ? (num - 1) % w : w - 1 - (num - 1) % w;

    // 전체 박스의 마지막 위치 찾기 (층, 열)
    int total_f = (n - 1) / w + 1;
    int total_c = (total_f % 2 != 0) ? (n - 1) % w : w - 1 - (n - 1) % w;

    // 내 위로 쌓인 층수 계산
    int ans = total_f - my_f + 1;
    
    bool is_empty = false;
    if (total_f % 2 != 0) { // 마지막 층이 순방향
        if (my_c > total_c) is_empty = true;
    } else { // 마지막 층이 역방향
        if (my_c < total_c) is_empty = true;
    }

    return is_empty ? ans - 1 : ans;
}