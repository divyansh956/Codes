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

void polynomialSubtraction(node *head3, node *head1, node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->exp == head2->exp)
        {
            insertAtTail(head3, head1->coef + head2->coef * -1, head1->exp);
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->exp > head2->exp)
        {
            insertAtTail(head3, head1->coef, head1->exp);
            head1 = head1->next;
        }
        else
        {
            insertAtTail(head3, head2->coef * -1, head2->exp);
            head2 = head2->next;
        }
    }

    while (head1 != NULL)
    {
        insertAtTail(head3, head1->coef, head1->exp);
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        insertAtTail(head3, head2->coef * -1, head2->exp);
        head2 = head2->next;
    }

    display(head3);
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;

    insertAtTail(head1, 3, 5);
    insertAtTail(head1, 4, 3);
    insertAtTail(head1, 2, 2);
    insertAtTail(head1, 9, 1);
    insertAtTail(head1, -8, 0);
    display(head1);

    insertAtTail(head2, 7, 6);
    insertAtTail(head2, 2, 5);
    insertAtTail(head2, -2, 4);
    insertAtTail(head2, 3, 3);
    insertAtTail(head2, 7, 2);
    display(head2);

    polynomialSubtraction(head3, head1, head2);
}
