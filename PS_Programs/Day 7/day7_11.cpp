#include <bits/stdc++.h>
using namespace std;

string removeSpaces(string str)
{
    string res;
    int n = str.length();
    int c1 = 0;
    int c2 = str.length() - 1;

    while (str[c1] == ' ')
    {
        c1++;
    }
    while (str[c2] == ' ')
    {
        c2--;
    }

    while (c1 < c2 + 1)
    {
        res += str[c1];
        c1++;
    }
    cout << n << endl;
    cout << res.length() << endl;
    return res;
}

int main()
{
    string str1;
    getline(cin, str1);

    cout << removeSpaces(str1) << endl;
}
