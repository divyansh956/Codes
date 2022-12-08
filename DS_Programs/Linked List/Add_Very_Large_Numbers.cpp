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

void display(node *head)
{
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

string addNumber(string s1, string s2)
{
    // Converting Into Linked List

    node *head1 = NULL;
    node *head2 = NULL;

    string temp;
    for (int i = s1.length() - 1; i >= 0; i -= 4)
    {
        for (int j = i; j > i - 4 && j >= 0; j--)
        {
            temp += to_string(s1[j] - '0');
        }

        reverse(temp.begin(), temp.end());
        insertAtHead(head1, stoi(temp));
        temp = "";
    }

    temp = "";
    for (int i = s2.length() - 1; i >= 0; i -= 4)
    {
        for (int j = i; j > i - 4 && j >= 0; j--)
        {
            temp += to_string(s2[j] - '0');
        }

        reverse(temp.begin(), temp.end());
        insertAtHead(head2, stoi(temp));
        temp = "";
    }

    Reverse(head1);
    Reverse(head2);

    // Logic

    node *head3 = NULL;
    int carry = 0;

    while (head1 != NULL && head2 != NULL)
    {
        int total = head1->data + head2->data + carry;
        int sum = total % 10000;
        carry = total / 10000;

        head1 = head1->next;
        head2 = head2->next;
        insertAtHead(head3, sum);
    }

    while (head1 != NULL)
    {
        int total = head1->data + carry;
        int sum = total % 10000;
        carry = total / 10000;

        head1 = head1->next;
        insertAtHead(head3, sum);
    }

    while (head2 != NULL)
    {
        int total = head2->data + carry;
        int sum = total % 10000;
        carry = total / 10000;

        head2 = head2->next;
        insertAtHead(head3, sum);
    }

    if (carry > 0)
    {
        insertAtHead(head3, carry);
    }

    // Converting Into String

    string ans = "";
    temp = "";

    while (head3 != NULL)
    {
        temp += to_string(head3->data);
        if (temp.length() < 4)
        {
            while (temp.length() != 4)
            {
                temp = "0" + temp;
            }
        }

        ans += temp;
        temp = "";

        head3 = head3->next;
    }

    // Removing Pre-Zeroes

    int i = 0;
    string res;

    while (ans[i] == '0')
    {
        i++;
    }

    for (int idx = i; idx < ans.length(); idx++)
    {
        res += ans[idx];
    }

    return res;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << addNumber(s1, s2) << endl;
}
