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

int countsumK(node *root, int sum)
{
    if (root == NULL)
    {
        return sum;
    }

    int take = countsumK(root->left, sum + root->data);

    int notTake = countsumK(root->right, sum + root->data);

    return max(take, notTake);
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
    root->right->right->left = new node(4);

    cout << countsumK(root, 0) << endl;
}
