#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    node *next;

    node(char val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, char val)
{
    node *n = new node(val);

    n->next = head;
    head = n;
}

void insertAtTail(node *&head, char val)
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

void arrangeCharacters(string &ss)
{
    node *head = NULL;

    for (int i = 0; i < ss.length(); i++)
    {
        insertAtTail(head, ss[i]);
    }

    node *q = head;
    string s = "aeiouAEIOU";

    vector<char> vowel;
    vector<char> consonant;

    while (q != NULL)
    {
        if (s.find(q->data) != string::npos)
        {
            vowel.push_back(q->data);
        }
        else
        {
            consonant.push_back(q->data);
        }
        q = q->next;
    }

    q = head;
    int i = 0;
    while (i < vowel.size())
    {
        q->data = vowel[i++];
        q=q->next;
    }

    i = 0;
    while (i < consonant.size())
    {
        q->data = consonant[i++];
        q=q->next;
    }

    q = head;
    i = 0;
    while (q != NULL)
    {
        ss[i] = q->data;
        i++;
        q = q->next;
    }
}

int main()
{
    string ss;
    cin >> ss;

    arrangeCharacters(ss);
    cout << ss << endl;
}
