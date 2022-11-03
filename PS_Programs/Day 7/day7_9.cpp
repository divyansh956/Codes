#include <bits/stdc++.h>
using namespace std;

void suffix(string str1)
{
    for (int i = str1.length() - 1; i >= 0; i--)
    {
        for (int j = i; j < str1.length(); j++)
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

    suffix(str1);
}
