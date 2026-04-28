#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> total;
    unordered_map<string, vector<pair<int, int>>> logs;

    for (int i = 0; i < genres.size(); i++) {
        total[genres[i]] += plays[i];
        logs[genres[i]].push_back({plays[i], i});
    }

    // 장르별 총 재생 횟수 기준 내림차순 정렬
    vector<pair<int, string>> rank;
    for (const auto& [key, value] : total)
        rank.push_back({value, key});
    sort(rank.begin(), rank.end(), greater<pair<int, string>>());

    // 각 장르 내의 곡들을 정렬
    for (auto& entry : logs) {
        sort(entry.second.begin(), entry.second.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second; // 재생수 같으면 인덱스 낮은 순
            return a.first > b.first; // 재생수 높은 순
        });
    }

    vector<int> answer;
    // 순위권 장르부터 최대 2곡씩 추출
    for (int i = 0; i < rank.size(); i++) {
        string target_genre = rank[i].second;
        auto& target_songs = logs[target_genre];

        // 장르 내 곡이 1개일 수도, 2개 이상일 수도 있음
        for (int j = 0; j < target_songs.size() && j < 2; j++) {
            answer.push_back(target_songs[j].second);
        }
    }

    return answer;
}