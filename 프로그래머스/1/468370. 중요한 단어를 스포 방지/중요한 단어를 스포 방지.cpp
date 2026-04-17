#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

struct WordInfo {
    string text;
    int start, end;
    bool is_spoiler = false;
};

int solution(string message, vector<vector<int>> spoiler_ranges) {
    vector<WordInfo> words;
    stringstream ss(message);
    string temp;
    int curr = 0;

    // 1. 단어 정보(텍스트, 시작인덱스, 끝인덱스) 추출
    while (ss >> temp) {
        int s = message.find(temp, curr);
        int e = s + temp.length() - 1;
        words.push_back({temp, s, e});
        curr = e + 1;
    }

    // 2. 각 단어가 스포일러 구간에 걸치는지 확인
    set<string> normal_words; // 스포 구간이 아닌 곳에 등장한 단어들 저장소
    for (auto& w : words) {
        for (auto& range : spoiler_ranges) {
            // 단어와 구간이 겹치는지 검사
            if (!(w.end < range[0] || w.start > range[1])) {
                w.is_spoiler = true;
                break;
            }
        }
        // 스포일러가 아닌 단어는 따로 저장
        if (!w.is_spoiler) normal_words.insert(w.text);
    }

    // 3. 순서대로 중요 단어 판별
    set<string> already_shown; // 이전에 공개된 스포 단어들
    int count = 0;

    for (auto& w : words) {
        if (w.is_spoiler) {
            // 조건: (일반 구간에 없어야 함) AND (이전에 공개된 적 없어야 함)
            if (normal_words.find(w.text) == normal_words.end() && 
                already_shown.find(w.text) == already_shown.end()) {
                count++;
            }
            // 중요 단어였든 아니든, 스포일러 단어이므로
            already_shown.insert(w.text);
        }
    }

    return count;
}