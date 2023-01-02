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

int countsumK(node *root, int k, int sum)
{
    if (root == NULL)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    if (sum == k)
    {
        return 1;
    }

    if (sum > k)
    {
        return 0;
    }

    int take = countsumK(root->left, k, sum + root->data);

    int notTake = countsumK(root->right, k, sum + root->data);

    return take + notTake;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(3);
    root->left->right = new node(2);
    root->right->left = new node(1);
    root->right->right = new node(4);
    root->right->right->left = new node(2);

    cout << countsumK(root, 5, 0) / 2 << endl;
}
