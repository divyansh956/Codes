#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int coef;
    int exp;
    node *next;

    node(int val1, int val2)
    {
        coef = val1;
        exp = val2;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val1, int val2)
{
    node *n = new node(val1, val2);

    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val1, int val2)
{
    node *n = new node(val1, val2);

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

    cout << "Polynomial: ";
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->coef << "x^" << temp->exp << " + ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAfter(node *&head, int val, int exp, int idx)
{
    node *n = new node(val, exp);

    if (idx == 0)
    {
        insertAtHead(head, val, exp);
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
        insertAtTail(head, val, exp);
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

void descending(node *&head, int coef, int ex)
{
    node *temp = head;
    int i = 0;

    while (temp != NULL && temp->exp > ex)
    {
        i++;
        temp = temp->next;
    }

    if (temp == head)
    {
        insertAtHead(head, coef, ex);
    }
    else
    {
        insertAfter(head, coef, ex, i);
    }
}

void deleteAtHead(node *&head)
{
    node *todelete = head;

    head = head->next;
    delete todelete;
}

void deleteVal(node *&head, int val, int ex)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty" << endl;
        return;
    }

    if ((head->coef == val && head->exp == ex) || head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;

    while (temp->next->coef != val && temp->next->exp != ex && temp->next->next != NULL)
    {
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void polynomialMultiplication(node *head3, node *head1, node *head2)
{
    node *p = head1;
    node *q = head2;

    while (q != NULL)
    {
        p = head1;
        while (p != NULL)
        {
            descending(head3, p->coef * q->coef, p->exp + q->exp);
            p = p->next;
        }
        q = q->next;
    }

    p = head3;

    while (p->next != NULL)
    {
        if (p->exp == p->next->exp)
        {
            p->coef = p->coef + p->next->coef;
            deleteVal(p, p->next->coef, p->next->exp);
        }
        else
        {
            p = p->next;
        }
    }
    display(head3);
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;

    insertAtTail(head1, 4, 3);
    insertAtTail(head1, 8, 1);
    insertAtTail(head1, -2, 2);
    insertAtTail(head1, -9, 0);
    display(head1);

    insertAtTail(head2, 5, 1);
    insertAtTail(head2, 2, 3);
    insertAtTail(head2, 5, 2);
    insertAtTail(head2, 2, 0);
    display(head2);

    polynomialMultiplication(head3, head1, head2);
}
