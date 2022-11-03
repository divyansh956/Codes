#include <bits/stdc++.h>
using namespace std;

void prefix(string str1)
{
    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << str1[j];
        }
        cout << endl;
    }
}

int main()
{
    string str1;
    cin >> str1;

    prefix(str1);
}
