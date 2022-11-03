#include <bits/stdc++.h>
using namespace std;

struct clock
{
    int hr;
    int min;
    int sec;
};

int main()
{
    struct clock c[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> c[i].hr;
        cin >> c[i].min;
        cin >> c[i].sec;
    }

    int c_sec = (c[0].sec + c[1].sec) % 60;
    int carry1 = (c[0].sec + c[1].sec) / 60;
    int c_min = (c[0].min + c[1].min + carry1) % 60;
    int carry2 = (c[0].min + c[1].min + carry1) / 60;
    int c_hr = c[0].hr + c[1].hr + carry2;
    
    cout << c_hr % 24 << " : " << c_min << " : " << c_sec << endl;
}
