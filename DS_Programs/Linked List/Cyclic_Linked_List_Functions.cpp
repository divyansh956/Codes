// Using 1 Based Indexing

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

void makeCycle(node *&head, int idx1, int idx2)
{
    if (idx1 > idx2)
    {
        swap(idx1, idx2);
    }

    idx1--;
    idx2--;

    node *temp1 = head;
    node *temp2 = head;

    while (idx1--)
    {
        temp1 = temp1->next;
    }
    while (idx2--)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

void cycleHead(node *&head)
{
    node *temp1 = head;
    node *temp2 = head;

    while (temp2 != NULL && temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;

        if (temp1 == temp2)
        {
            break;
        }
    }

    node *start = head;
    int i = 1;

    while (temp2 != start)
    {
        i++;
        start = start->next;
        temp2 = temp2->next;
    }
    cout << "Cycle Head: " << start->data << endl;
}

void cycleLength(node *&head)
{
    node *temp1 = head;
    node *temp2 = head->next;

    while (temp2 != NULL && temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;

        if (temp1 == temp2)
        {
            break;
        }
    }

    int i = 0;
    temp1 = temp1->next;

    while (temp2 != temp1)
    {
        i++;
        temp1 = temp1->next;
    }
    cout << "Cycle Length: " << ++i << endl;
}

void cycleDetection(node *&head)
{
    node *temp1 = head;
    node *temp2 = head;

    while (temp2 != NULL && temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;

        if (temp1 == temp2)
        {
            cout << "Cylic Linked List" << endl;
            return;
        }
    }
    cout << "Not a Cyclic Linked List" << endl;
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

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    deleteVal(head, 3);
    insertAtHead(head, 9);
    insertAtTail(head, 6);
    insertAfter(head, 10, 1);
    insertAtTail(head, 11);

    display(head);
    cout << Count(head) << endl;

    cycleDetection(head);
    makeCycle(head, 7, 3);
    cycleDetection(head);

    cycleLength(head);
    cycleHead(head);
}
