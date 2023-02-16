#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<node *> HT(15, NULL);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int rem = x % 10;

        if (HT[rem] == NULL)
        {
            node *p = new node(x);
            HT[rem] = p;
        }
        else
        {
            node *t = HT[rem];
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = new node(x);
        }
    }

    for (int i = 0; i < 15; i++)
    {
        cout << i << ": ";
        node *t = HT[i];
        while (t != NULL)
        {
            cout << t->data << " ";
            t = t->next;
        }

        cout << endl;
    }
}
