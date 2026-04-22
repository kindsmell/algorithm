#include <vector>
#include <unordered_set>
#include <algorithm> 

using namespace std;

int solution(vector<int> nums) {
    // 1. 종류를 담기
    unordered_set<int> species(nums.begin(), nums.end());

    // 2. 가질 수 있는 최대 마릿수
    int goal = nums.size() / 2;

    // 3. 종류의 수와 goal 중 작은 값이 정답.
    return min((int)species.size(), goal);
}