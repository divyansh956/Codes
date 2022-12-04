#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    cin >> s1;

    string s2;
    cin >> s2;

    if (s2.compare(s1) == 0)
    {
        cout << "Strings are Equal";
    }
    else
    {
        cout << "Strings are Not Equal";
    }

    return 0;
}