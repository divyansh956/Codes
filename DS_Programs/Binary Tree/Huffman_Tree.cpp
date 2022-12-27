#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    int freq;
    node *next;
    node *left;
    node *right;

    node()
    {
        data = '\0';
        freq = 0;
        next = NULL;
        left = NULL;
        right = NULL;
    }
};

void PostOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->freq << " ";
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->freq << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void InOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->freq << " ";
    InOrder(root->right);
}

void levelOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *p = q.front();
        q.pop();

        if (p != NULL)
        {
            cout << p->freq << " ";

            if (p->left != NULL)
            {
                q.push(p->left);
            }

            if (p->right != NULL)
            {
                q.push(p->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

void PQInsert(node *&root, node *x)
{
    node *p = root;
    node *q = NULL;

    while (p != NULL && p->freq <= x->freq)
    {
        q = p;
        p = p->next;
    }

    if (q == NULL)
    {
        x->next = p;
        root = x;
        return;
    }

    x->next = q->next;
    q->next = x;
}

node *PQDelete(node *&root)
{
    node *p = root;
    root = root->next;

    return p;
}

node *HuffmanTree(char sym[], int freq[], int n)
{
    node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        node *x = new node();

        x->freq = freq[i];
        x->data = sym[i];

        PQInsert(root, x);
    }

    for (int i = 0; i < n - 1; i++)
    {
        node *x = PQDelete(root);
        node *y = PQDelete(root);

        node *z = new node();

        z->left = x;
        z->right = y;
        z->freq = x->freq + y->freq;

        PQInsert(root, z);
    }

    return PQDelete(root);
}

int main()
{
    int n;
    cin >> n;

    char sym[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sym[i];
    }

    int freq[n];
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];
    }

    node *root = HuffmanTree(sym, freq, n);

    preOrder(root);
    cout << endl;

    InOrder(root);
    cout << endl;

    PostOrder(root);
    cout << endl;

    levelOrder(root);
    cout << endl;
}
