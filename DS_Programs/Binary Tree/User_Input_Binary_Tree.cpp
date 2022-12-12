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

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void createTree(node *&root)
{
    int choice;

    cout << "Whether The Left of " << root->data << " Exist(1/0): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Data For Left of " << root->data << ": ";
        int x;
        cin >> x;

        node *n = new node(x);
        root->left = n;

        createTree(n);
    }

    cout << "Whether The Right of " << root->data << " Exist(1/0): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Data For Right of " << root->data << ": ";
        int x;
        cin >> x;

        node *n = new node(x);
        root->right = n;

        createTree(n);
    }
}

int main()
{
    node *root = NULL;

    cout << "Enter Data For Root Node: ";
    int x;
    cin >> x;

    root = new node(x);

    createTree(root);
    preOrder(root);
}
