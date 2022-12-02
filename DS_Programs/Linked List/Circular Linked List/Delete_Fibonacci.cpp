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
void deleteFibonaaciTerms(node *&head, vector<int> &dp)
{
    if (Count(head) == 1)
    {
        if (dp[head->data] == 1)
        {
            deletePos(head, 1);
        }
        else
        {
            return;
        }
    }

    if (dp[head->data] == 1)
    {
        deletePos(head, 1);
        deleteFibonaaciTerms(head, dp);
    }
    else
    {
        deleteFibonaaciTerms(head->next, dp);
    }
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 3);
    insertAtTail(head, 0);
    insertAtTail(head, 5);
    insertAtTail(head, 11);
    insertAtTail(head, 4);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 10);
    insertAtTail(head, 9);
    display(head);

    vector<int> dp(10000, 0);
    dp[0] = 1;
    dp[1] = 1;

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i < 10; i++)
    {
        int curr = prev1 + prev2;
        dp[curr] = 1;
        prev2 = prev1;
        prev1 = curr;
    }

    deleteFibonaaciTerms(head, dp);
    display(head);
}
