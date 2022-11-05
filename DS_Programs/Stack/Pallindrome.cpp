#include <bits/stdc++.h>
using namespace std;

string reverse(string ss, int n)
{
    stack<char> s[n];
    string ans;

    int i = 0;
    while (i < n)
    {
        s->push(ss[i++]);
    }

    while (!s->empty())
    {
        ans += s->top();
        s->pop();
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    string s1 = to_string(n);
    string s2 = reverse(s1, s1.length());

    if (s1.compare(s2) == 0)
    {
        cout << "Pallindrome" << endl;
    }
    else
    {
        cout << "Not Pallindrome" << endl;
    }
}
