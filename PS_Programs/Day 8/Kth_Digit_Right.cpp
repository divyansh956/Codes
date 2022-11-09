#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    long long int res = pow(a, b);

    string temp = to_string(res);
    reverse(temp.begin(), temp.end());
    
    cout << temp[k - 1] << endl;
}
