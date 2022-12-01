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

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        n->next = n;
        head = n;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void insertAfter(node *&head, int val, int idx)
{
    node *n = new node(val);

    if (idx == 0)
    {
        insertAtHead(head, val);
        return;
    }

    node *temp = head;

    int i = 1;
    for (i = 1; i < idx && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if (temp->next == head && i == idx)
    {
        insertAtTail(head, val);
        return;
    }

    if (idx != i)
    {
        cout << "Index " << idx << " Out of Range : Linked List Size = " << i << endl;
        return;
    }

    n->next = temp->next;
    temp->next = n;
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = head->next;
    head = head->next;

    delete todelete;
}

void deletePos(node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty" << endl;
        return;
    }

    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    int cnt = 1;

    while (cnt != pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

int Count(node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    node *temp = head;
    temp = temp->next;
    int i = 1;

    while (temp != head)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

void display(node *head)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty" << endl;
        return;
    }

    cout << "Circular Linked List: ";
    node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != head);

    cout << endl;
}

void concate(node *&head3, node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;

    while (temp1->next != head1)
    {
        insertAtTail(head3, temp1->data);
        temp1 = temp1->next;
    }
    insertAtTail(head3, temp1->data);

    while (temp2->next != head2)
    {
        insertAtTail(head3, temp2->data);
        temp2 = temp2->next;
    }
    insertAtTail(head3, temp2->data);
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;

    insertAtTail(head1, 1);
    insertAtTail(head1, 3);
    insertAtHead(head1, 5);
    insertAtHead(head1, 9);
    insertAtTail(head1, 11);
    insertAtTail(head1, 6);
    display(head1);

    insertAtHead(head2, 4);
    insertAtTail(head2, 2);
    insertAfter(head2, 10, 1);
    display(head2);

    concate(head3, head1, head2);
    display(head3);
}
