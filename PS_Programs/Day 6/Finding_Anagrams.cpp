#include <bits/stdc++.h>
using namespace std;

void anagram(string a, string b)
{
    unordered_map<char, int> mp;

    for (int i = 0; i < a.length(); i++)
    {
        mp[a[i]]++;
    }

    for (int i = 0; i < b.length(); i++)
    {
        mp[b[i]]--;
    }

    for (auto x : mp)
    {
        if (x.second != 0)
        {
            cout << x.first << " ";
        }
    }
    cout << endl;
}

int main()
{
    string a, b;
    cin >> a >> b;

    anagram(a, b);
}
