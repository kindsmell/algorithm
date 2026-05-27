#include <string>

using namespace std;

string solution(string s) {
    bool is_first = true;
    
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            is_first = true;
        } else {
            if (is_first) {
                s[i] = toupper(s[i]);
                is_first = false;
            } else {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    return s;
}