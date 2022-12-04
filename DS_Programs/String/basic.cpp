#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    cin >> str; // Include Only Word
    cout << str << endl;

    string str1(5, 'k');
    cout << str1 << endl;

    string str2 = "CodingIsLove";
    cout << str2 << endl;

    string str3;
    getline(cin, str3); // Used to Enter a line
    cout << str3 << endl;

    return 0;
}