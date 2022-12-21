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

node *BSTinsert(node *&root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
        return root;
    }

    if (val < root->data)
    {
        root->left = BSTinsert(root->left, val);
    }
    else
    {
        root->right = BSTinsert(root->right, val);
    }

    return root;
}

int main()
{
    node *root = NULL;

    BSTinsert(root, 130);
    BSTinsert(root, 70);
    BSTinsert(root, 60);
    BSTinsert(root, 30);
    BSTinsert(root, 10);
    BSTinsert(root, 100);

    InOrder(root);
}
