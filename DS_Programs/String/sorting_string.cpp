#include <iostream>
#include <string>
#include <algorithm> // used for sort

using namespace std;

int main()
{
    string s1 = "dcbsdjcbsjckgbjoie";

    sort(s1.begin(), s1.end());
    cout << s1 << endl;

    for (int i = 0; i < s1.length(); i++)
    {
        cout << s1[i] << " ";
    }

    return 0;
}