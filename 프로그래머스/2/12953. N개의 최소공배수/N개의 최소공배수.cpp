#include <vector>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}