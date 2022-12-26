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

bool IsIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    bool cond1 = root1->data == root2->data;
    bool cond2 = IsIdentical(root1->left, root2->left);
    bool cond3 = IsIdentical(root1->right, root2->right);

    return cond1 & cond2 & cond3;
}

int main()
{
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    root1->right->right = new node(7);

    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);
    root2->right->left = new node(6);
    root2->right->right = new node(7);

    cout << IsIdentical(root1, root2) << endl;
}
