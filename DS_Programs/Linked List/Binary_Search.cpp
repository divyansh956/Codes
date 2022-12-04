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
        cout << "NULL" << endl;
        return;
    }

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *middle(node *st, node *en)
{
    if (st == NULL)
    {
        return NULL;
    }

    node *slow = st;
    node *fast = st->next;

    while (fast != en)
    {
        fast = fast->next;
        if (fast != en)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

node *binarySearch(node *&head, int k)
{
    node *st = head;
    node *en = NULL;

    while (en == NULL || en != st)
    {
        node *mid = middle(st, en);

        if (mid->data == k)
        {
            return mid;
        }

        else if (mid->data < k)
        {
            st = mid->next;
        }

        else
        {
            en = mid;
        }
    }
    return NULL;
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);

    int k;
    cin >> k;

    cout << binarySearch(head, k) << endl;
}
