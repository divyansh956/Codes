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

void deletekthNodefromLast(node *&head, int k)
{
    node *p = head;
    node *q = head;

    while (q != NULL && k--)
    {
        q = q->next;
    }

    if (q == NULL && k == 0)
    {
        node *todelete = head;
        head = head->next;
        delete todelete;

        return;
    }
    else if (q == NULL && k > 0)
    {
        cout << "Element Does Not Exist" << endl;
        return;
    }

    q = q->next;

    while (q != NULL)
    {
        q = q->next;
        p = p->next;
    }

    node *todelete = p->next;
    p->next = p->next->next;

    delete todelete;
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

    int k;
    cin >> k;

    deletekthNodefromLast(head, k);
    display(head);
}
