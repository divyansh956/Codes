#include <bits/stdc++.h>
using namespace std;

void decimalToBinary(int n)
{
    stack<int> s[100];
    while (n != 0)
    {
        s->push(n % 2);
        n = n / 2;
    }

    while (!s->empty())
    {
        cout << s->top() << " ";
        s->pop();
    }
}

int main()
{
    int n;
    cin >> n;

    decimalToBinary(n);
}
