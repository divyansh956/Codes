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

node* Reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    head = prevptr;
    return head;
}

bool isPallindrome(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node *slow = head;
    node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = Reverse(slow->next);
    slow = slow->next;
    node *temp = head;

    while (slow != NULL)
    {
        if (temp->data != slow->data)
        {
            return false;
        }
        slow = slow->next;
        temp = temp->next;
    }
    return true;
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 3);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    display(head);

    cout << isPallindrome(head) << endl;
}
