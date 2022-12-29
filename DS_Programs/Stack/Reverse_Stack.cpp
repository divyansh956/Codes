#include <bits/stdc++.h>
using namespace std;

void Reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    Reverse(s);
    s.push(num);
}

int main()
{
    int n;
    cin >> n;

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    Reverse(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
