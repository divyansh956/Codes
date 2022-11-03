#include <bits/stdc++.h>
using namespace std;

bool validVariable(string str)
{
    int i = 1;
    bool flag = true;
    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_' || str[0] == '$'))
    {
        flag = false;
    }

    while (str[i] != '\0' && flag == true)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_' || str[i] == '$' || (str[i] >= '0' && str[i] <= '9')))
        {
            flag = false;
            break;
        }
        i++;
    }
    return flag;
}

int main()
{
    string str;
    cin >> str;

    cout << validVariable(str) << endl;
}
