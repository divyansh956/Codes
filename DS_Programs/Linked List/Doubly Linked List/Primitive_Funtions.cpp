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

void insertAtHead(node *&head, node *&prev, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    n->next = head;
    head->prev = n;
    head = n;
}

void insertAtTail(node *&head, node *&prev, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        insertAtHead(head, prev, val);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void insertAfter(node *&head, node *&prev, node *p, int val)
{
    if (p == NULL)
    {
        node *n = new node(val);

        if (head == NULL)
        {
            head = n;
            return;
        }

        n->next = head;
        head->prev = n;
        head = n;
        return;
    }

    if (p->next == NULL)
    {
        node *n = new node(val);

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
        return;
    }

    node *n = new node(val);

    node *q = p->next;
    p->next = n;
    n->prev = p;
    n->next = q;
    q->prev = n;
}

void insertBefore(node *&head, node *&prev, node *p, int val)
{
    if (p == NULL || p->prev == NULL)
    {
        node *n = new node(val);

        if (head == NULL)
        {
            head = n;
            return;
        }

        n->next = head;
        head->prev = n;
        head = n;
        return;
    }

    node *n = new node(val);

    node *q = p->prev;
    q->next = n;
    n->prev = q;
    n->next = p;
    p->prev = n;
}

void deleteAtHead(node *&head, node *&prev)
{
    if (head == NULL)
    {
        cout << "Void Deletion" << endl;
        return;
    }

    if (head->next == NULL)
    {
        node *todelete = head;

        head = head->next;
        delete todelete;

        return;
    }

    node *todelete = head;

    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deleteAtTail(node *&head, node *&prev)
{
    if (head == NULL)
    {
        cout << "Void Deletion" << endl;
        return;
    }

    if (head->next == NULL)
    {
        node *todelete = head;

        head = head->next;
        delete todelete;

        return;
    }

    node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    node *todelete = temp->next;

    temp->next = NULL;

    delete todelete;
}

void deleteBefore(node *&head, node *&prev, node *p)
{
    if (p == NULL || p->prev == NULL)
    {
        cout << "Void Deletion" << endl;
        return;
    }

    if (p->prev->prev == NULL)
    {
        node *todelete = head;

        p->prev = NULL;
        head = head->next;

        delete todelete;

        return;
    }

    node *todelete = p->prev;
    node *q = p->prev->prev;

    p->prev = q;
    q->next = p;

    delete todelete;
}

void deleteAfter(node *&head, node *&prev, node *p)
{
    if (p == NULL || p->next == NULL)
    {
        cout << "Void Deletion" << endl;
        return;
    }

    if (p->next->next == NULL)
    {
        node *todelete = p->next;

        p->next = NULL;

        delete todelete;

        return;
    }

    node *todelete = p->next;
    node *q = p->next->next;

    p->next = q;
    q->prev = p;

    delete todelete;
}

void display(node *head)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty" << endl;
        return;
    }

    cout << "Linked List: ";
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    node *prev = NULL;

    insertAtTail(head, prev, 7);
    insertAtTail(head, prev, 1);
    insertAtTail(head, prev, 4);
    insertAtHead(head, prev, 2);
    insertAtHead(head, prev, 5);
    insertAtHead(head, prev, 6);
    insertAtHead(head, prev, 3);
   
    display(head);
}
