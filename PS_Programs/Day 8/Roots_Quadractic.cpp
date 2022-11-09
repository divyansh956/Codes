#include <bits/stdc++.h>
using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;

    float disc = (b * b) - (4 * a * c);

    if (disc == 0)
    {
        cout << "Roots are Equal" << endl;
        cout << -b / (2 * a) << " " << -b / (2 * a) << endl;
    }
    else if (disc < 0)
    {
        cout << "Roots are Imaginary and Distinct" << endl;
        cout << setprecision(2) << -b / (2 * a) << "+" << sqrt(abs(disc)) / (2 * a) << "i"
             << " " << -b / (2 * a) << "-" << sqrt(abs(disc)) / (2 * a) << "i" << endl;
    }
    else
    {
        cout << "Roots are Real and Distinct" << endl;
        cout << (-b + sqrt(disc)) / (2 * a) << " " << (-b - sqrt(disc)) / (2 * a) << endl;
    }
}
