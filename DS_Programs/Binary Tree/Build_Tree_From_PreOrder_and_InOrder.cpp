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

int search(string inOrder, int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (curr == (inOrder[i] - '0'))
        {
            return i;
        }
    }
    return -1;
}

node *buildTree(string preOrder, string inOrder, int start, int end)
{
    static int idx = 0;

    if (start > end)
    {
        return NULL;
    }

    int curr = preOrder[idx] - '0';
    idx++;

    node *root = new node(curr);

    if (start == end)
    {
        return root;
    }

    int pos = search(inOrder, start, end, curr);

    root->left = buildTree(preOrder, inOrder, start, pos - 1);
    root->right = buildTree(preOrder, inOrder, pos + 1, end);

    return root;
}

void InOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    string preOrder, inOrder;
    cin >> preOrder >> inOrder;

    node *root = buildTree(preOrder, inOrder, 0, preOrder.size() - 1);
    InOrder(root);
}
