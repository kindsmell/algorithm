#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int h = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    int n = citations.size();

    for(int i = 0; i < n; i++)
    {
       h++;
        if(h > citations[i])
        {
            h--;
            break;
        }
    }
    return h;
}