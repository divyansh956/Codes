#include <bits/stdc++.h>
using namespace std;

void minimum(stack<int> s1, int n)
{
    stack<int> s2;
    s2.push(s1.top());
    s1.pop();

    int cnt = 0;

    while (!s1.empty())
    {
        if (s2.top() >= s1.top())
        {
            s2.push(s1.top());
            s1.pop();
        }
        else
        {
            int temp = s1.top();
            s1.pop();

            while (!s2.empty() && s2.top() < temp)
            {
                s1.push(s2.top());
                s2.pop();
                cnt++;
            }

            s2.push(temp);
            while (cnt--)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
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
