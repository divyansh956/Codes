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

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int currDiameter = leftHeight + rightHeight + 1;

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max({currDiameter, leftDiameter, rightDiameter});
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

    cout << diameter(root) << endl;
}