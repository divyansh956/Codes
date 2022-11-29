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

    display(head);

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    display(head);

    deleteVal(head, 3);
    deleteVal(head, 78);
    display(head);

    insertAtHead(head, 9);
    insertAtTail(head, 6);
    display(head);

    insertAfter(head, 10, 5);
    insertAfter(head, 15, 9);
    insertAtTail(head, 11);
    display(head);

    cout << Count(head) << endl;
}
