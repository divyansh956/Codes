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

node *back;
node *front;

void Initialize()
{
    front = NULL;
    back = NULL;
}

int IsEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueqe(int val)
{
    node *n = new node(val);

    if (front == NULL)
    {
        back = n;
        front = n;
        return;
    }

    back->next = n;
    back = n;
}

void dequeue()
{
    if (IsEmpty())
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    node *todelete = front;
    front = front->next;

    delete todelete;
}

int peek()
{
    if (IsEmpty())
    {
        cout << "Queue Is Empty" << endl;
        return -1;
    }

    return front->data;
}

int main()
{
    node *back;
    node *front;
    Initialize();

    enqueqe(2);
    enqueqe(1);
    enqueqe(5);
    enqueqe(6);
    enqueqe(9);

    dequeue();
    cout << peek() << endl;

    dequeue();
    dequeue();
    cout << peek() << endl;
    dequeue();
    dequeue();

    cout << IsEmpty() << endl;
}
