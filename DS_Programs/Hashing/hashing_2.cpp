#include <bits/stdc++.h>
using namespace std;

void linearProbing(char str[], int idx[], int n)
{
    int mx = *max_element(idx, idx + n);

    char ans[mx + 1];
    for (int i = 0; i < mx + 1; i++)
    {
        ans[i] = '0';
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[idx[i]] == '0')
        {
            ans[idx[i]] = str[i];
        }
        else
        {
            int c = 0;
            while (ans[(idx[i] + c) % (mx + 1)] != '0')
            {
                c++;
            }
            ans[(idx[i] + c) % (mx + 1)] = str[i];
        }
    }

    for (int i = 0; i < mx + 1; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    char str[n];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    int idx[n];
    for (int i = 0; i < n; i++)
    {
        cin >> idx[i];
    }

    linearProbing(str, idx, n);
}
