#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "fam";
    string s2 = "ily";

    // s1.append(s2);
    cout << s1 << endl;

    cout << s1 + s2 << endl;
    s2 = s1 + s2;
    cout << s2 << endl;

    cout << s1[1] << endl;

    string str = "dcfdkjcnck h kjhdja";
    cout << str << endl;
    str.clear();
    cout << 1 << str << 1 << endl;

    return 0;
}