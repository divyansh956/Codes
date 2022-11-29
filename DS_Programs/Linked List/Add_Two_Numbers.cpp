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

string addNumber(node *&head3, node *head1, node *head2)
{
    int carry = 0;

    while (head1 != NULL && head2 != NULL)
    {
        int total = head1->data + head2->data + carry;
        int sum = total % 10;
        carry = total / 10;

        head1 = head1->next;
        head2 = head2->next;
        insertAtHead(head3, sum);
    }

    while (head1 != NULL)
    {
        int total = head1->data + carry;
        int sum = total % 10;
        carry = total / 10;

        head1 = head1->next;
        insertAtHead(head3, sum);
    }

    while (head2 != NULL)
    {
        int total = head2->data + carry;
        int sum = total % 10;
        carry = total / 10;

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

    for (int i = 0; i < s1.length(); i++)
    {
        insertAtHead(head1, s1[i] - '0');
    }

    for (int i = 0; i < s2.length(); i++)
    {
        insertAtHead(head2, s2[i] - '0');
    }

    cout << addNumber(head3, head1, head2) << endl;
}
