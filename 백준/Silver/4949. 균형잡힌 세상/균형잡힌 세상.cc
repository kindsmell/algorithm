#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    while (true)
    {
        string tmp;
        getline(cin, tmp);
        if (tmp == ".")
            break;

        stack<char> s;
        bool isError = false;

        for (char ch : tmp)
        {
            if (ch == '(' || ch == '[')
            {
                s.push(ch); // 여는 괄호는 무조건 push
            }
            else if (ch == ')')
            {
                // 스택이 비어있거나 짝이 안 맞으면 에러
                if (s.empty() || s.top() != '(')
                {
                    isError = true;
                    break;
                }
                s.pop();
            }
            else if (ch == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    isError = true;
                    break;
                }
                s.pop();
            }
        }

        if (!isError && s.empty())
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
    return 0;
}