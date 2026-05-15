#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> unique_numbers;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int num = stoi(numbers.substr(0, i));
            unique_numbers.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    for (int num : unique_numbers) {
        if (isPrime(num)) {
            answer++;
        }
    }
    
    return answer;
}