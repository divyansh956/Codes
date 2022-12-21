#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node *father;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        father = NULL;
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
        p->left->father = p;
    }
    else
    {
        p->right = new node(val);
        p->right->father = p;
    }
}

node *BSTsearch(node *root, int val)
{
    while (root != NULL)
    {
        if (root->data == val)
        {
            return root;
        }
        else if (root->data < val)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
}

node *minimum(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *maximum(node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

int successor(node *p)
{
    node *q;

    if (p->right != NULL)
    {
        q = minimum(p->right);
    }
    else
    {
        q = p->father;
        while (q != NULL && q->right == p)
        {
            p = q;
            q = q->father;
        }
    }
    return q->data;
}

int predesessor(node *p)
{
    node *q;

    if (p->left != NULL)
    {
        q = maximum(p->left);
    }
    else
    {
        q = p->father;
        while (q != NULL && q->left == p)
        {
            p = q;
            q = q->father;
        }
    }
    return q->data;
}

int main()
{
    node *root = NULL;
    BSTinsert(root, 200);
    BSTinsert(root, 500);
    BSTinsert(root, 10);
    BSTinsert(root, 20);
    BSTinsert(root, 60);
    BSTinsert(root, 300);

    InOrder(root);
    cout << endl;

    int x;
    cin >> x;
    node *temp = BSTsearch(root, x);

    cout << successor(temp) << endl;
    cout << predesessor(temp) << endl;
}
