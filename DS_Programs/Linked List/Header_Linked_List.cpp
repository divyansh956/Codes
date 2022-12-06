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

void insertAtHead(node *&root, node *&head, int val)
{
    node *n = new node(val);

    root->next = n;
    n->next = head;
    head = n;

    root->data++;
}

void insertAtTail(node *&root, node *&head, int val)
{
    node *n = new node(val);

    if (root->next == NULL)
    {
        root->next = n;
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;

    root->data++;
}

void insertAfter(node *&root, node *&head, node *&q, int val)
{
    if (q == root)
    {
        insertAtHead(root, head, val);
        return;
    }

    if (q->next == NULL)
    {
        insertAtTail(root, head, val);
        return;
    }

    node *n = new node(val);

    n->next = q->next;
    q->next = n;

    root->data++;
}

void deleteAtHead(node *&root, node *&head)
{
    if (head == NULL)
    {
        cout << "Void Deletion" << endl;
        return;
    }

    node *del = root->next;

    root->next = root->next->next;
    head = root->next;

    delete del;

    root->data--;
}

void deleteAtTail(node *&root, node *&head)
{
    if (head == NULL)
    {
        cout << "Void Deletion" << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;

        root->data--;

        return;
    }

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    node *del = temp->next;

    temp->next = temp->next->next;

    delete del;

    root->data--;
}

void deleteAfter(node *&root, node *&head, node *&q)
{
    if (q == root)
    {
        deleteAtHead(root, head);
        return;
    }

    if (q->next == NULL)
    {
        deleteAtTail(root, head);
        return;
    }

    node *del = q->next;

    q->next = q->next->next;
    delete del;

    root->data--;
}

void display(node *root, node *head)
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
    node *root = new node(0);
    node *head = NULL;

    insertAtHead(root, head, 1);
    insertAtHead(root, head, 3);
    insertAtHead(root, head, 4);
    insertAfter(root, head, head->next->next, 2);
    display(root, head);

    deleteAfter(root, head, head->next);
    display(root, head);
}
