#include <iostream>
#include <climits>
using namespace std;

void swaps(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    cin >> a >> b;

    swaps(&a, &b);

    cout << a << " " << b << endl;

    return 0;
}
