#include <bits/stdc++.h>
using namespace std;

void reverse(string ss, int n)
{
    stack<char> s[n];
    int i = 0;
    while (i < n)
    {
        s->push(ss[i++]);
    }

    while (!s->empty())
    {
        cout << s->top();
        s->pop();
    }
}

int main()
{
    string ss;
    cin >> ss;

    int n = ss.length();
    reverse(ss, n);
}
