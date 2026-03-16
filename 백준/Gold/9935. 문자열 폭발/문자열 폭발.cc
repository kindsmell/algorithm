#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    string bomb;
    string s;
    cin >> str >> bomb;

    char last = bomb.back();
    for (char c : str)
    {
        s.push_back(c);

        if (s.length() >= bomb.length() && (c == last))
        {
            bool is_bomb = true;
            for (int i = 0; i < bomb.length(); i++)
            {
                if (s[s.length() - bomb.length() + i] != bomb[i])
                {
                    is_bomb = false;
                    break;
                }
            }

            if (is_bomb == true)
            {
                for (int i = 0; i < bomb.length(); i++)
                    s.pop_back();
            }
        }
    }

    if (s.length() == 0)
        cout << "FRULA";
    else
        cout << s;
}