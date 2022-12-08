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

void deleteDuplicates(node *&head)
{
    node *p = head;

    while (p != NULL)
    {
        node *q = p->next;
        node *r = p;
        
        while (q != NULL)
        {
            if (q->data == p->data)
            {
                node *del = q;
                q = q->next;
                r->next = q;

                delete del;
            }
            else
            {
                r = r->next;
                q = q->next;
            }
        }

        p = p->next;
    }
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 3);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 9);
    insertAtTail(head, 9);
    insertAtTail(head, 5);
    display(head);

    deleteDuplicates(head);
    display(head);
}


/******************************************************************************************************************************/


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

void deleteDuplicates(node *&head)
{
    vector<int> dp(10000, 0);
    node *temp = head;

    while (temp != NULL)
    {
        dp[temp->data]++;
        temp = temp->next;
    }

    temp = head;

    while (temp->next != NULL)
    {
        if (dp[temp->next->data] > 1)
        {
            node *todelete = temp->next;

            temp->next = temp->next->next;

            delete todelete;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (dp[head->data] > 1)
    {
        node *todelete = head;

        head = head->next;
        delete todelete;
    }
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 4);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 5);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 9);
    display(head);

    deleteDuplicates(head);
    display(head);
}
