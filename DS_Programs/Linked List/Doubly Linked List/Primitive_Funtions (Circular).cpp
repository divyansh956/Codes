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
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }

    node *temp = head->prev;

    n->next = head;
    head->prev = n;

    temp->next = n;
    n->prev = temp;
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

    node *temp = head->prev;

    n->next = head;
    head->prev = n;

    temp->next = n;
    n->prev = temp;
}

void insertAfter(node *&head, node *&prev, node *p, int val)
{
    if (p == NULL)
    {
        insertAtHead(head, prev, val);
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
    if (p == NULL || p == head)
    {
        insertAtHead(head, prev, val);
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

    if (head->next == head)
    {
        node *todelete = head;
        delete todelete;

        head = NULL;

        return;
    }

    node *todelete = head;

    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->prev->next;

    delete todelete;
}

void deleteAtTail(node *&head, node *&prev)
{
    if (head == NULL)
    {
        cout << "Void Deletion" << endl;
        return;
    }

    if (head->next == head)
    {
        node *todelete = head;
        delete todelete;

        head = NULL;

        return;
    }

    node *todelete = head->prev;

    head->prev->prev->next = head;
    head->prev = head->prev->prev;

    delete todelete;
}

void deleteBefore(node *&head, node *&prev, node *p)
{
    if (p == NULL)
    {
        cout << "Void Deletion" << endl;
        return;
    }

    if (p->next == p && p->prev == p)
    {
        node *todelete = p;
        delete todelete;

        head = NULL;

        return;
    }

    if (p->prev == head)
    {
        deleteAtHead(head, prev);
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
    if (p == NULL)
    {
        cout << "Void Deletion" << endl;
        return;
    }

    if (p->next == p && p->prev == p)
    {
        node *todelete = p;
        delete todelete;

        head = NULL;

        return;
    }

    if (p->next == head)
    {
        deleteAtHead(head, prev);
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

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != head);

    cout << endl;
}

int main()
{
    node *head = NULL;
    node *prev = NULL;

    insertAtTail(head, prev, 1);
    insertAtTail(head, prev, 2);
    insertAtTail(head, prev, 3);
    insertAtTail(head, prev, 4);
    insertAtTail(head, prev, 5);
    insertAtTail(head, prev, 6);
    
    display(head);
}
