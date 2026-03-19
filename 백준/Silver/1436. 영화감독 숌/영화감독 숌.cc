#include <iostream>
#include <string>
using namespace std;

bool is_triple(string str)
{
    for (int i = 0; i < str.length() - 2; i++)
    {
        if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6')
            return true;
    }
    return false;
}

int main()
{
    int n;

    cin >> n;

    int num = 666;
    int cnt = 1;
    while (true)
    {
        string str = to_string(num);
        if (is_triple(str))
        {
            if (cnt == n)
            {
                cout << num;
                return 0;
            }
            cnt++;
        }
        num++;
    }
}