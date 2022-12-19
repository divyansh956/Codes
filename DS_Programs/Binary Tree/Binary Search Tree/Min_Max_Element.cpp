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

int minimum(node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int maximum(node *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
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

    cout << minimum(root) << endl;
    cout << maximum(root) << endl;
}
