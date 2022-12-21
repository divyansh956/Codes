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
node*p=NULL;
node *buildTree(string postOrder, string inOrder, int start, int end)
{
    static int idx = end;

    if (start > end)
    {
        return NULL;
    }

    int curr = postOrder[idx] - '0';
    idx--;

    p = new node(curr);

    if (start == end)
    {
        return p;
    }

    int pos = search(inOrder, start, end, curr);

    p->right = buildTree(postOrder, inOrder, pos + 1, end);
    p->left = buildTree(postOrder, inOrder, start, pos - 1);

    return p;
}

void In(node *root, string &in)
{
    if (root == NULL)
    {
        return;
    }

    In(root->left, in);
    in += to_string(root->data);
    In(root->right, in);
}

void Pre(node *root, string &pre)
{
    if (root == NULL)
    {
        return;
    }

    pre += to_string(root->data);
    Pre(root->left, pre);
    Pre(root->right, pre);
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

struct node *MirrorImage(node *root)
{
    string inOrder = "", postOrder = "";

    In(root, inOrder);
    Pre(root, postOrder);
    reverse(postOrder.begin(), postOrder.end());

    node *st = buildTree(postOrder, inOrder, 0, inOrder.length() - 1);
    return st;
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
    InOrder(root);

    node *stt = MirrorImage(root);
    InOrder(stt);
}
