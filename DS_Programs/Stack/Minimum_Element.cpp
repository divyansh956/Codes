#include <bits/stdc++.h>
using namespace std;

void minimum(stack<int> s1, int n)
{
    stack<int> s2;
    s2.push(s1.top());
    s1.pop();

    for (int i = 1; i < n; i++)
    {
        if (s2.top() > s1.top())
        {
            while (!s1.empty() && (s2.top() < s1.top()))
            {
                s2.pop();
            }
            s2.push(s1.top());
            s1.pop();
        }
        else
        {
            s1.pop();
        }
    }
    cout << s2.top() << endl;
}

int main()
{
    int n;
    cin >> n;

    stack<int> s1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s1.push(x);
    }
    minimum(s1, n);
}
