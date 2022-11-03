#include <bits/stdc++.h>
using namespace std;

void frequencyCount(string str1)
{
    map<char, int> mp;
    int n = str1.length();
    for (int i = 0; i < n; i++)
    {
        mp[str1[i]]++;
    }
    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
}

int main()
{
    string str1;
    cin >> str1;

    frequencyCount(str1);
}
