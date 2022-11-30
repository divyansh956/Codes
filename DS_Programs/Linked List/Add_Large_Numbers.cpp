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

    cout << "Linked List: ";
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Reverse(node *&head)
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
}

bool check = true;

string addNumber(node *&head3, node *head1, node *head2)
{
    int carry = 0;

    while (head1 != NULL && head2 != NULL)
    {
        int mx = max(head1->data, head1->data);
        int mxlen = to_string(mx).length();

        int total = head1->data + head2->data + carry;
        int len1 = to_string(total).length();

        int cnt = (len1 > mxlen) && (head1->next != NULL || head2->next !=NULL);

        int digit = (to_string(total)).length();
        int temp = pow(10, digit - cnt);
        int sum = total % temp;
        carry = total / temp;

        head1 = head1->next;
        head2 = head2->next;
        insertAtHead(head3, sum);
    }

    while (head1 != NULL)
    {
        int total = head1->data + carry;
        int sum = total % 1000000000;
        carry = total / 1000000000;

        head1 = head1->next;
        insertAtHead(head3, sum);
    }

    while (head2 != NULL)
    {
        int total = head2->data + carry;
        int sum = total % 1000000000;
        carry = total / 1000000000;

        head2 = head2->next;
        insertAtHead(head3, sum);
    }

    if (carry > 0)
    {
        insertAtHead(head3, carry);
    }

    string ans;

    while (head3 != NULL)
    {
        ans += to_string(head3->data);
        head3 = head3->next;
    }

    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;

    for (int i = 0; i < s1.length(); i += 9)
    {
        string temp = s1.substr(i, 9);
        insertAtHead(head1, stoi(temp));
    }

    for (int i = 0; i < s2.length(); i += 9)
    {
        string temp = s2.substr(i, 9);
        insertAtHead(head2, stoi(temp));
    }

    display(head1);
    display(head2);

    cout << addNumber(head3, head1, head2) << endl;
}
