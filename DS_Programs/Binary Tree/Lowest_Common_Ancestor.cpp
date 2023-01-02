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

node *LCA(node *root, int x, int y)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == x || root->data == y)
    {
        return root;
    }

    node *left = LCA(root->left, x, y);
    node *right = LCA(root->right, x, y);

    if (left == NULL)
    {
        return right;
    }

    if (right == NULL)
    {
        return left;
    }

    return root;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->left = new node(8);

    cout << LCA(root, root->left->left->data, root->right->data)->data << endl;
}
