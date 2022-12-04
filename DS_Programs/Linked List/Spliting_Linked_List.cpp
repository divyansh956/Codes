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
        cout << "NULL" << endl;
        return;
    }

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

vector<node *> divideIn_N_Parts(node *&head, int k)
{
    vector<node *> ans;
    int len = Count(head);

    int N = len / k;
    int extra = len % k;

    node *p = head;

    while (p != NULL)
    {
        ans.push_back(p);

        int currlen = 1;
        while (currlen < N)
        {
            p = p->next;
            currlen++;
        }

        if (extra > 0 && len > k)
        {
            p = p->next;
            extra--;
        }

        node *temp = p->next;
        p->next = NULL;
        p = temp;
    }

    while (len < k)
    {
        ans.push_back(NULL);
        len++;
    }

    return ans;
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 1);
    insertAtTail(head, 4);
    display(head);

    int k;
    cin >> k;

    vector<node *> v = divideIn_N_Parts(head, k);

    for (int i = 0; i < k; i++)
    {
        display(v[i]);
    }
}

/*******************************************************************************************************************************************/

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
        cout << "NULL" << endl;
        return;
    }

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

void divideIn_N_Parts(node *&head, int k)
{
    int len = Count(head);

    int N = len / k;
    int extra = len % k;

    node *p = head;

    while (p != NULL)
    {
        int currlen = 1;

        while (currlen < N)
        {
            cout << p->data << " ";
            p = p->next;
            currlen++;
        }

        if (extra > 0 && len > k)
        {
            cout << p->data << " ";
            p = p->next;
            extra--;
        }

        node *temp = p->next;
        p->next = NULL;
        cout << p->data << endl;
        p = temp;
    }

    while (len < k)
    {
        cout << "NULL" << endl;
        len++;
    }
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 1);
    insertAtTail(head, 4);
    display(head);

    int k;
    cin >> k;

    divideIn_N_Parts(head, k);
}
