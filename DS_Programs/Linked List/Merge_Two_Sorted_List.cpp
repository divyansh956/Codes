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
    for (i = 1; i < idx && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    if (idx == i - 1)
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

    head = head->next;
    delete todelete;
}

void deleteVal(node *&head, int val)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty" << endl;
        return;
    }

    if (head->data == val || head->next == NULL)
    {
        if (head->data != val)
        {
            cout << "Element: " << val << " Not Found" << endl;
            return;
        }

        deleteAtHead(head);
        return;
    }

    node *temp = head;

    while (temp->next->data != val && temp->next->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->next->next == NULL && temp->next->data != val)
    {
        cout << "Element: " << val << " Not Found" << endl;
        return;
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
    int i = 0;

    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

void ascending(node *&head, int val)
{
    node *temp = head;
    int i = 0;

    while (temp != NULL && temp->data <= val)
    {
        i++;
        temp = temp->next;
    }

    if (temp == head)
    {
        insertAtHead(head, val);
    }
    else
    {
        insertAfter(head, val, i);
    }
}

void display(node *head)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty" << endl;
        return;
    }

    node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void mergeList(node *&head3, node *head1, node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            insertAtTail(head3, head1->data);
            head1 = head1->next;
        }
        else
        {
            insertAtTail(head3, head2->data);
            head2 = head2->next;
        }
    }
    while (head1 != NULL)
    {
        insertAtTail(head3, head1->data);
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        insertAtTail(head3, head2->data);
        head2 = head2->next;
    }

    display(head3);
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;

    ascending(head1, 3);
    ascending(head2, 2);
    ascending(head1, 1);
    ascending(head2, 4);
    ascending(head1, 8);
    ascending(head1, 5);
    ascending(head1, 15);
    ascending(head2, 20);
    ascending(head2, 7);
    ascending(head1, 22);
    
    display(head1);
    display(head2);

    mergeList(head3, head1, head2);
}
