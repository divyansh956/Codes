#include <bits/stdc++.h>
using namespace std;

int main()
{
    char *p = (char *)malloc(40);

    for (int i = 0; i < 10; i++)
    {
        scanf("%c", (p + i));
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%c ", *(p + i));
    }
    cout << endl;
}
