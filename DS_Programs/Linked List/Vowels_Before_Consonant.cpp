#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    node *next;

    node(char val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, char val)
{
    node *n = new node(val);

    n->next = head;
    head = n;
}

void insertAtTail(node *&head, char val)
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
    for (i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    if (idx == i - 1)
    {
        insertAtTail(head, val);
        return;
    }

    n->next = temp->next;
    temp->next = n;
}

void arrangeCharacters(string &ss)
{
    node *head = NULL;

    for (int i = 0; i < ss.length(); i++)
    {
        insertAtTail(head, ss[i]);
    }

    node *q = head;
    int idx = 0;
    string s = "aeiouAEIOU";

    if (s.find(q->next->data) == string::npos)
    {
        idx++;
    }

    while (q->next != NULL)
    {
        if (s.find(q->next->data) != string::npos)
        {
            insertAfter(head, q->next->data, idx);
            idx++;
            q->next = q->next->next;
        }
        else
        {
            q = q->next;
        }
    }

    q = head;
    int i = 0;

    while (q != NULL)
    {
        ss[i] = q->data;
        i++;
        q = q->next;
    }
}

int main()
{
    string ss;
    cin >> ss;

    arrangeCharacters(ss);
    cout << ss << endl;
}
