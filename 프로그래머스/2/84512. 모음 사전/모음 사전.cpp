#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    int rate[5] = {781, 156, 31, 6, 1};
    
    string vowels = "AEIOU";
    
    for (int i = 0; i < word.length(); i++) {
        // 현재 글자가 AEIOU 중 몇 번째 인덱스인지 찾기
        int index = vowels.find(word[i]);
        
        answer += (index * rate[i]) + 1;
    }
    
    return answer;
}