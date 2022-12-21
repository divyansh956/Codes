#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void InOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void BSTinsert(node *&root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
        return;
    }

    node *p = NULL;
    node *q = root;

    while (q != NULL)
    {
        p = q;

        if (q->data > val)
        {
            q = q->left;
        }
        else
        {
            q = q->right;
        }
    }

    if (p->data > val)
    {
        p->left = new node(val);
    }
    else
    {
        p->right = new node(val);
    }
}

int main()
{
    node *root = new node(100);
    root->left = new node(50);
    root->right = new node(150);
    root->left->left = new node(20);
    root->left->right = new node(70);
    root->right->left = new node(120);
    root->right->right = new node(290);

    BSTinsert(root, 130);
    InOrder(root);
}
