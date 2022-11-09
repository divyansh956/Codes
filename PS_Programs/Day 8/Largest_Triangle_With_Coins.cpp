#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    float cir;
    cin >> cir;

    if (n == 1)
    {
        cout << "Not Possible" << endl;
        return 0;
    }

    float r = cir / (2 * 3.14);

    int x = 1;
    int sum = 0;
    int cnt = 0;

    while (sum < n)
    {
        sum += x++;
        cnt++;
    }
    if (sum != n)
    {
        cout << "Not Possible" << endl;
    }
    else
    {
        float base = (cnt * 2 - 2) * r;
        float area = (sqrt(3) / 4) * base * base;

        cout << "Area: " << (sqrt(3) / 4) * base * base << endl;

        float height = area * 2 / base;
        cout << "Height: " << height << endl;
    }
}
