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

void Initialize(node *head)
{
    head = NULL;
}

void push(node *&head, int val)
{
    node *n = new node(val);

    n->next = head;
    head = n;
}

void pop(node *&head)
{
    node *todelete = head;

    head = head->next;
    delete todelete;
}

int top(node *&head)
{
    return head->data;
}

int IsEmpty(node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

int main()
{
    node *head;
    Initialize(head);

    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 9);
    push(head, 6);
    push(head, 11);
    pop(head);
    cout << top(head) << endl;
    pop(head);
    cout << top(head) << endl;
    cout << IsEmpty(head) << endl;
}
