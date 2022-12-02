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

void deleteFibonaaciTerms(node *&head)
{
    vector<int> dp(10000, 0);
    dp[0] = 1;
    dp[1] = 1;

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i < 20; i++)
    {
        int curr = prev1 + prev2;
        dp[curr] = 1;
        prev2 = prev1;
        prev1 = curr;
    }

    int cnt = 1;

    while (dp[head->data] == 1)
    {
        node *todelete = head;
        head = head->next;
        delete todelete;

        if (head==NULL)
        {
            return;
        }
        
    }

    node *q = head;

    while (q->next != NULL)
    {
        if (dp[q->next->data] == 1)
        {
            node *todelete = q->next;
            q->next = q->next->next;
            delete todelete;
        }
        else
        {
            q = q->next;
        }
    }
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 6);
    insertAtTail(head, 3);
    insertAtTail(head, 0);
    insertAtTail(head, 5);
    insertAtTail(head, 11);
    insertAtTail(head, 4);
    insertAtTail(head, 0);
    insertAtTail(head, 6);
    insertAtTail(head, 8);
    insertAtTail(head, 7);
    insertAtTail(head, 10);
    insertAtTail(head, 9);
    insertAtTail(head, 8);
    display(head);

    deleteFibonaaciTerms(head);
    display(head);
}
