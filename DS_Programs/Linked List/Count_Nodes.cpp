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

void display(node *head)
{
    if (head == NULL)
    {
        cout << "Linked List Is Empty" << endl;
        return;
    }

    int cnt = 0;

    node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "Nodes: " << cnt << endl;
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    deleteVal(head, 3);
    insertAtHead(head, 9);
    insertAtTail(head, 6);
    insertAfter(head, 10, 5);
    insertAtTail(head, 11);

    display(head);
}


/**********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

struct node
{
     int info;
     struct node *next;
};

struct node *start;
int cnt = 0;
int even = 0, odd = 0;

struct node *GetNode()
{

     struct node *p;
     p = start;
     p = (struct node *)malloc(sizeof(struct node *));
     return p;
}

void InsEnd(int x)
{
     struct node *q = start;
     while (q->next != NULL)
     {
          q = q->next;
     }
     struct node *p = GetNode();
     p->info = x;
     p->next = NULL;
     q->next = p;
}

void InsBeg(int x)
{
     struct node *p;
     p = GetNode();
     p->info = x;
     p->next = start;
     start = p;
}

void traverse()
{
     struct node *p;
     p = start;
     while (p != NULL)
     {
          if (p->info % 2 == 0)
          {
               even++;
          }
          else
          {
               odd++;
          }

          cnt++;
          printf("%d ", p->info);
          p = p->next;
     }
}


int main()
{
     start = NULL;
     InsBeg(100);
     InsBeg(23);
     InsBeg(300);
     InsBeg(500);
     InsBeg(97);
     InsBeg(300);
     InsEnd(1000);
     InsEnd(39);

     printf("Linked List: ");
     traverse();
     printf("\nNodes: %d", cnt);
     printf("\nEven: %d", even);
     printf("\nOdd: %d", odd);
}
