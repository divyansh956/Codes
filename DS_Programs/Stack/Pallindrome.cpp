#include <bits/stdc++.h>
using namespace std;

string reverse(string ss, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(ss[i++], ss[j--]);
    }
    return ss;
}

int main()
{
    int n;
    cin >> n;

    string s1 = to_string(n);
    string s2 = reverse(s1, s1.length());

    if (s1.compare(s2) == 0)
    {
        cout << "Pallindrome" << endl;
    }
    else
    {
        cout << "Not Pallindrome" << endl;
    }
}
