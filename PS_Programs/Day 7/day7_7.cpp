#include <bits/stdc++.h>
using namespace std;

string concat(string str1, string str2)
{
    for (int i = 0; i < str2.length(); i++)
    {
        str1 += str2[i];
    }
    return str1;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << concat(str1, str2) << endl;
}
