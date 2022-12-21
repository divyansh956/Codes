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

bool isleft(node *root)
{
    if (root->father->left == root)
    {
        return true;
    }
    return false;
}

node *minimum(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *successor(node *p)
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
    return q;
}

int BSTdelete(node *&root, node *p)
{
    if (p->left == NULL && p->right == NULL)
    {
        node *q = p->father;

        if (q == NULL)
        {
            root = NULL;
        }
        else
        {
            if (isleft(p))
            {
                q->left = NULL;
            }
            else
            {
                q->right = NULL;
            }
        }

        int x = p->data;
        delete p;
        return x;
    }

    if (p->left == NULL || p->right == NULL)
    {
        node *l = p->left;
        node *r = p->right;
        node *c;

        if (l == NULL)
        {
            c = r;
        }
        else
        {
            c = l;
        }

        node *q = p->father;

        if (q == NULL)
        {
            if (p->left != NULL)
            {
                root = p->left;
            }
            else
            {
                root = p->right;
            }
        }
        else
        {
            if (isleft(p))
            {
                q->left = c;
            }
            else
            {
                q->right = c;
            }
        }

        c->father = q;
        int x = p->data;
        delete p;
        return x;
    }

    node *q = successor(p);
    int x = BSTdelete(root, q);
    int y = p->data;
    p->data = x;
    return y;
}

int main()
{
    node *root = NULL;
    BSTinsert(root, 200);
    BSTinsert(root, 500);
    BSTinsert(root, 10);
    BSTinsert(root, 5);
    BSTinsert(root, 20);
    BSTinsert(root, 60);
    BSTinsert(root, 300);

    InOrder(root);
    cout << endl;

    BSTdelete(root, root->left->right);
    BSTdelete(root, root->right);
    InOrder(root);
}
