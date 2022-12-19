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

node *BSTsearch(node *root, int val)
{
    while (root != NULL)
    {
        if (root->data == val)
        {
            return root;
        }
        else if (root->data < val)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
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

    cout << BSTsearch(root, 70) << endl;
}
