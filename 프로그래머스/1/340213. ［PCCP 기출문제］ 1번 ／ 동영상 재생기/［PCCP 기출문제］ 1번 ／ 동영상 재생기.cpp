#include <string>
#include <vector>

using namespace std;

int totalSeconds(string time)
{
    int minutes = stoi(time.substr(0, 2)); 
    int seconds = stoi(time.substr(3, 2));
    return( minutes * 60 + seconds);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {

    int curr = totalSeconds(pos);
    int op_s = totalSeconds(op_start);
    int op_e = totalSeconds(op_end);
    int v_len = totalSeconds(video_len);
    
    
    for(int i = 0; i < commands.size(); i++)
    {
        if(curr >= op_s && curr <= op_e) curr = op_e;
        if(commands[i] == "next")
        {
            curr+= 10;
            if(curr >= v_len)   curr = v_len;
        }    
        else
            curr-= 10;
            if(curr <= 0)    curr = 0;
        if(curr >= op_s && curr <= op_e) curr = op_e;
    }
    
    string m = to_string(curr / 60);
    string s = to_string(curr % 60);
    
    if(m.length() == 1) m = "0" + m;
    if(s.length() == 1) s = "0" + s;

    string answer = m + ":" + s;
    return answer;
};