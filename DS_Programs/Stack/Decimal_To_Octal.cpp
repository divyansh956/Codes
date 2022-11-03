#include <bits/stdc++.h>
using namespace std;

void decimalToOctal(int n)
{
    stack<int> s[100];
    while (n != 0)
    {
        s->push(n % 8);
        n = n / 8;
    }

    while (!s->empty())
    {
        cout << s->top();
        s->pop();
    }
}

int main()
{
    int n;
    cin >> n;

    decimalToOctal(n);
}
