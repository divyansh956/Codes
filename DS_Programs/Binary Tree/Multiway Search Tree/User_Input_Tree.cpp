#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    node *child;
    node *sibling;

    node(char val)
    {
        data = val;
        child = NULL;
        sibling = NULL;
    }
};

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->child);
    preOrder(root->sibling);
}

void levelOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *p = q.front();
        q.pop();

        if (p != NULL)
        {
            cout << p->data << " ";

            if (p->child != NULL)
            {
                q.push(p->child);
            }

            if (p->sibling != NULL)
            {
                q.push(p->sibling);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

void createTree(node *&root)
{
    int choice;

    cout << "Whether The Child of " << root->data << " Exist(1/0): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Data For Child of " << root->data << ": ";
        char x;
        cin >> x;

        node *n = new node(x);
        root->child = n;

        createTree(n);
    }

    cout << "Whether The Sibling of " << root->data << " Exist(1/0): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Data For Sibling of " << root->data << ": ";
        char x;
        cin >> x;

        node *n = new node(x);
        root->sibling = n;

        createTree(n);
    }
}

int main()
{
    node *root = NULL;

    cout << "Enter Data For Root Node: ";
    char x;
    cin >> x;

    root = new node(x);

    createTree(root);
    preOrder(root);
}
