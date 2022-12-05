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

void rotate(node *&head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
    {
        return;
    }

    node *temp = head;
    int len = 1;

    while (temp->next != NULL)
    {
        len++;
        temp = temp->next;
    }
    temp->next = head;

    k = k % len;
    k = len - k;

    while (k--)
    {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    display(head);

    int k;
    cin >> k;

    rotate(head, k);
    display(head);
}
