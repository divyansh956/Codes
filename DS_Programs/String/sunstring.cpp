#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "IamNoob";
    string s = s1.substr(2, 4);
    cout << s << endl;

    string s2 = "786";
    int x = stoi(s2); // String To Integer
    cout << x + 2 << endl;

    int a = 43;
    cout << to_string(x) + "2" << endl; // Integer To String

    return 0;
}