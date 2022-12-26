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

    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

int count_N1_Nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    if (root->left != NULL && root->right != NULL)
    {
        return count_N1_Nodes(root->left) + count_N1_Nodes(root->right);
    }

    return count_N1_Nodes(root->left) + count_N1_Nodes(root->right) + 1;
}

bool IsComplete(node *root)
{
    if (height(root->left) == height(root->right) && count_N1_Nodes(root) == 0)
    {
        return true;
    }

    return false;
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

    cout << IsComplete(root) << endl;
}
