#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    vector<int> score;

    for (int i = 0; i < dartResult.size(); i++) {
        if (isdigit(dartResult[i])) {
            int num;
            if (dartResult[i] == '1' && i + 1 < dartResult.size() && dartResult[i + 1] == '0') {
                num = 10;
                i++;
            } else {
                num = dartResult[i] - '0';
            }

            char bonus = dartResult[++i];

            if (bonus == 'S') num = num;
            else if (bonus == 'D') num *= num;
            else num = num * num * num;

            score.push_back(num);
        } else if (dartResult[i] == '*') {
            score.back() *= 2;
            if (score.size() >= 2)
                score[score.size() - 2] *= 2;
        } else if (dartResult[i] == '#') {
            score.back() *= -1;
        }
    }

    int answer = 0;
    for (int x : score)
        answer += x;

    return answer;
}