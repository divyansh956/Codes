#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "abc";
    cout << str << endl;

    str.clear();

    if (str.empty())
    {
        cout << "String is Empty" << endl;
    }
    else
    {
        cout << "String is Not Empty" << endl;
    }

    string s1 = "IamNoob";

    // Index_No  //No_of_Elements
    s1.erase(3, 3);
    cout << s1 << endl;

    cout << s1.find("am") << endl;

    // string s2 = "Noo";
    s1.insert(3, "Noo");
    cout << s1 << endl;

    cout << s1.size() << endl;

    return 0;
}