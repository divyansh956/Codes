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

void reverseContent(node *&head)
{
    node *q = head;

    while (q != NULL)
    {
        string temp = to_string(q->data);
        reverse(temp.begin(), temp.end());
        q->data = stoi(temp);

        q = q->next;
    }
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 12);
    insertAtTail(head, 23);
    insertAtTail(head, 37);
    insertAtTail(head, 46);
    insertAtTail(head, 54);
    insertAtTail(head, 68);
    insertAtTail(head, 79);
    display(head);

    reverseContent(head);
    display(head);
}
