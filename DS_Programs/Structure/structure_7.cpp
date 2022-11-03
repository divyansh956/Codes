#include <bits/stdc++.h>
using namespace std;

struct student
{
    int roll;
    string name;
    int chem_marks;
    int maths_marks;
    int phy_marks;
};

int main()
{
    struct student c[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> c[i].roll;
        cin >> c[i].name;
        cin >> c[i].chem_marks;
        cin >> c[i].maths_marks;
        cin >> c[i].phy_marks;
    }

    for (int i = 0; i < 5; i++)
    {
        float avg = (c[i].chem_marks + c[i].maths_marks + c[i].phy_marks) / 3.0;
        cout << c[i].name << " " << avg << endl;
    }
}
