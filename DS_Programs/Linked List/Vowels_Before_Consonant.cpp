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


/**************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    char info;
    struct node *Next;
};

char DelAft(struct node **p)
{
    char x;
    struct node *q;
    q = (*p)->Next;
    (*p)->Next = q->Next;
    x = q->info;
    free(q);
    return x;
}

struct node *GetNode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}

void InsBeg(struct node **START, char x)
{
    struct node *p;
    p = GetNode();
    p->info = x;
    p->Next = *START;
    *START = p;
}

char DelBeg(struct node **START)
{
    struct node *p;
    char x;
    p = (*START);
    (*START) = (*START)->Next;
    x = p->info;
    free(p);
    return x;
}

void InsEnd(struct node **START, char x)
{
    struct node *q, *p;
    q = *START;
    if (q == NULL)
    {
        InsBeg(START, x);
    }
    else
    {
        while (q->Next != NULL)
            q = q->Next;
        p = GetNode();
        p->info = x;
        p->Next = NULL;
        q->Next = p;
    }
}

void InsAft(struct node **p, char x)
{
    struct node *q;
    q = GetNode();
    q->info = x;
    q->Next = (*p)->Next;
    (*p)->Next = q;
}

void Traverse(struct node **START)
{
    struct node *p;
    p = *START;
    while (p != NULL)
    {
        printf("%c\t", p->info);
        p = p->Next;
    }
}

struct node *order(struct node **start)
{
    struct node *p, *c, *n;
    p = NULL;
    c = NULL;
    n = *start;

    while ((n != NULL) && (n->info == 'a' || n->info == 'e' || n->info == 'i' || n->info == 'o' || n->info == 'u'))
    {
        p = n;
        c = n;
        n = n->Next;
    }

    while (n != NULL)
    {
        if (n->info == 'a' || n->info == 'e' || n->info == 'i' || n->info == 'o' || n->info == 'u')
        {
            if (p == NULL)
            {
                InsBeg(start, n->info);
                p = *start;
                n = n->Next;
                DelAft(&c);
            }
            else
            {
                InsAft(&p, n->info);
                p = p->Next;
                n = n->Next;
                DelAft(&c);
            }
        }
        else
        {
            c = n;
            n = n->Next;
        }
    }
    return *start;
}

int main()
{
    struct node *p, *q;

    p = NULL;

    InsEnd(&p, 'i');
    InsEnd(&p, 'm');
    InsEnd(&p, 'i');
    InsEnd(&p, 'a');

    Traverse(&p);
    printf("\n");
    
    q = order(&p);
    Traverse(&q);
}
