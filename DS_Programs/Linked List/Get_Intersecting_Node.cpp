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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
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

node *getIntersectionNode(node *head1, node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }

    node *p = head1;
    node *q = head2;

    while (p != q)
    {
        p = p == NULL ? head2 : p->next;
        q = q == NULL ? head1 : q->next;
    }

    return p;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    insertAtTail(head1, 2);
    insertAtTail(head1, 1);
    insertAtTail(head1, 3);
    insertAtHead(head1, 4);
    insertAtHead(head1, 5);
    display(head1);

    insertAtTail(head2, 9);
    insertAtTail(head2, 8);
    insertAtTail(head2, 7);
    insertAtHead(head2, 6);
    insertAtHead(head2, 3);

    node *temp1 = head1->next->next->next;
    node *temp2 = head2->next;
    temp1->next = temp2;
    head2->next = temp1;

    display(head2);

    node *x = getIntersectionNode(head1, head2);
    if (x == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << x->data << endl;
    }
}
