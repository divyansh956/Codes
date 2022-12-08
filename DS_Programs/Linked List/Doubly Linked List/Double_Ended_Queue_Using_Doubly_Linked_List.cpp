#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void Initialize(node *&front, node *&rear)
{
    front = NULL;
    rear = NULL;
}

int IsEmpty(node *front, node *rear)
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}

void push_front(node *&front, node *&rear, int val)
{
    node *n = new node(val);

    if (front == NULL)
    {
        front = n;
        return;
    }

    n->next = front;
    front->prev = n;
    front = n;
}

void push_back(node *&front, node *&rear, int val)
{
    node *n = new node(val);

    if (rear == NULL)
    {
        front = n;
        rear = n;
        return;
    }

    rear->next = n;
    n->prev = rear;
    rear = n;
}

void pop_front(node *&front, node *&rear)
{
    if (IsEmpty(front, rear))
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    if (front->next == NULL)
    {
        node *del = front;
        delete del;

        front = NULL;
        rear = NULL;

        return;
    }

    node *todelete = front;

    front = front->next;
    front->prev = NULL;

    delete todelete;
}

void pop_back(node *&front, node *&rear)
{
    if (IsEmpty(front, rear))
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    if (rear->prev == NULL)
    {
        node *del = rear;
        delete del;

        front = NULL;
        rear = NULL;

        return;
    }

    node *todelete = rear;

    rear->prev->next = NULL;
    rear = rear->prev;

    delete todelete;
}

int Front(node *front, node *rear)
{
    if (IsEmpty(front, rear))
    {
        cout << "Queue Is Empty" << endl;
        return -1;
    }

    return front->data;
}

int Back(node *front, node *rear)
{
    if (IsEmpty(front, rear))
    {
        cout << "Queue Is Empty" << endl;
        return -1;
    }

    return rear->data;
}

void display(node *front, node *rear)
{
    if (rear == NULL)
    {
        cout << "Queue Is Empty" << endl;
        return;
    }

    node *p = front;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    node *rear;
    node *front;

    Initialize(front, rear);

    push_back(front, rear, 2);
    push_back(front, rear, 1);
    push_back(front, rear, 6);
    push_front(front, rear, 7);
    push_back(front, rear, 9);
    push_back(front, rear, 5);
    push_front(front, rear, 3);
    push_front(front, rear, 11);
    display(front, rear);

    pop_back(front, rear);
    pop_front(front, rear);
    pop_front(front, rear);
    pop_front(front, rear);
    display(front, rear);
}
