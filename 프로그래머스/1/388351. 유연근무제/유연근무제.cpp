#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int time_limit(int time){
    int tmp = (time / 100) * 60 + (time % 100);
    int total = tmp + 10;
    return (total / 60) * 100 + total % 60;
}

map<int, set<int>> invalid_idx = {
    {1, {6,7}}, //월 1 -> 6,7
    {2, {5,6}}, //화 2 -> 5 6
    {3, {4,5}}, //수 3 -> 4 5 
    {4, {3,4}}, //목 4 -> 3 4
    {5, {2,3}}, //금 5 -> 2 3
    {6, {1,2}}, //토 6 -> 1 2
    {7, {1,7}}  //일 7 -> 1 7
};


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {

    int cnt = 0;
    
    for(int i = 0; i < schedules.size(); i++)
    {   
        int flag = 1;
        int limit = time_limit(schedules[i]);
        
        for(int j = 0; j < 7; j++)
        {
            if(invalid_idx[startday].count(j + 1))
                continue;
            if(timelogs[i][j] > limit)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1) cnt++;
    }
    
    return cnt;
}