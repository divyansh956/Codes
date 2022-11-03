#include <bits/stdc++.h>
using namespace std;

bool validsameParenthesis(string ss)
{
    stack<char> s[100];
    int i = 0;
    while (ss[i] != '\0')
    {
        if (ss[i] == '[' || ss[i] == '{' || ss[i] == '(')
        {
            s->push(ss[i]);
        }
        else
        {
            if (ss[i] == ']')
            {
                if (!s->empty() && s->top() == '[')
                {
                    s->pop();
                }
                else
                {
                    return false;
                }
            }
            else if (ss[i] == '}')
            {
                if (!s->empty() && s->top() == '{')
                {
                    s->pop();
                }
                else
                {
                    return false;
                }
            }
            else if (ss[i] == ')')
            {
                if (!s->empty() && s->top() == '(')
                {
                    s->pop();
                }
                else
                {
                    return false;
                }
            }
        }
        i++;
    }
    if (!s->empty())
    {
        return false;
    }
    return true;
}

int main()
{
    string ss;
    cin >> ss;

    cout << validsameParenthesis(ss) << endl;
}
