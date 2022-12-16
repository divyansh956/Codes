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

node *buildTree(string postOrder, string inOrder, int start, int end)
{
    static int idx = end;

    if (start > end)
    {
        return NULL;
    }

    int curr = postOrder[idx] - '0';
    idx--;

    node *root = new node(curr);

    if (start == end)
    {
        return root;
    }

    int pos = search(inOrder, start, end, curr);

    root->right = buildTree(postOrder, inOrder, pos + 1, end);
    root->left = buildTree(postOrder, inOrder, start, pos - 1);

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
    string postOrder, inOrder;
    cin >> postOrder >> inOrder;

    node *root = buildTree(postOrder, inOrder, 0, postOrder.size() - 1);
    InOrder(root);
}
