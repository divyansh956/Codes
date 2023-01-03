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

void ZigZag(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> currlevel;
    stack<node *> nextlevel;
    bool leftToRight = true;

    currlevel.push(root);

    while (!currlevel.empty())
    {
        node *temp = currlevel.top();
        currlevel.pop();

        if (temp != NULL)
        {
            cout << temp->data << " ";

            if (leftToRight == true)
            {
                if (temp->left != NULL)
                {
                    nextlevel.push(temp->left);
                }

                if (temp->right != NULL)
                {
                    nextlevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    nextlevel.push(temp->right);
                }

                if (temp->left != NULL)
                {
                    nextlevel.push(temp->left);
                }
            }
        }

        if (currlevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currlevel, nextlevel);
        }
    }
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
    root->right->right->left = new node(8);
    root->right->right->right = new node(9);

    ZigZag(root);
}
