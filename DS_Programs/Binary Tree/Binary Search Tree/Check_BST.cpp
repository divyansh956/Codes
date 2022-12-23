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

bool isBST(node *root, node *mn, node *mx)
{
    if (root == NULL)
    {
        return true;
    }

    if (mn != NULL && root->data <= mn->data)
    {
        return false;
    }

    if (mx != NULL && root->data >= mx->data)
    {
        return false;
    }

    bool leftValid = isBST(root->left, mn, root);
    bool rightValid = isBST(root->right, root, mx);

    return leftValid & rightValid;
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

    cout << isBST(root, NULL, NULL) << endl;
}
