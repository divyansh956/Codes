#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1 = "siwovmcyqismj";

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] >= 'a' && s1[i] <= 'z')
        {
            s1[i] -= 32; // Upper Case
        }
    }
    cout << s1 << endl;

    string s2 = "BUCFBWIUDSWK";

    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] >= 'A' && s2[i] <= 'Z')
        {
            s2[i] += 32; // Lower Case
        }
    }
    cout << s2 << endl;

    string s3 = "shnuscnvkmi";
    
    transform(s3.begin(), s3.end(), s3.begin(), ::toupper);
    cout << s3 << endl;
    transform(s3.begin(), s3.end(), s3.begin(), ::tolower);
    cout << s3 << endl;

    return 0;
}