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

void Swap(node *&head, int idx1, int idx2)
{
    int val1 = head->data, val2 = head->data;

    node *temp1 = head;
    node *temp2 = head;

    for (int i = 1; i < idx1 - 1; i++)
    {
        temp1 = temp1->next;
    }
    val1 = temp1->next->data;

    for (int i = 1; i < idx2 - 1; i++)
    {
        temp2 = temp2->next;
    }
    val2 = temp2->next->data;

    node *n1 = new node(val1);
    node *n2 = new node(val2);

    if (idx1 + 1 == idx2)
    {
        temp1->next = n2;
        n2->next = n1;

        node *todelete = temp2->next;
        n1->next = temp2->next->next;

        delete todelete;
        return;
    }

    if (idx2 + 1 == idx1)
    {
        temp2->next = n1;
        n1->next = n2;

        node *todelete = temp1->next;
        n2->next = temp1->next->next;

        delete todelete;
        return;
    }

    n2->next = temp1->next->next;
    temp1->next = n2;
    n1->next = temp2->next->next;
    temp2->next = n1;
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

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    deleteVal(head, 3);
    insertAtHead(head, 9);
    insertAtTail(head, 6);
    insertAfter(head, 10, 5);
    insertAtTail(head, 11);
    display(head);

    Swap(head, 3, 2);
    Swap(head, 4, 5);
    display(head);
}
