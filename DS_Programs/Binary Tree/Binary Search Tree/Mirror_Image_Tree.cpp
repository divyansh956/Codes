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

void PostOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

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

void In(node *root, string &in)
{
    if (root == NULL)
    {
        return;
    }

    In(root->left, in);
    in = to_string(root->data) + in;
    In(root->right, in);
}

void Pre(node *root, string &post)
{
    if (root == NULL)
    {
        return;
    }

    post = to_string(root->data) + post;
    Pre(root->left, post);
    Pre(root->right, post);
}

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

node *MirrorImage(node *root)
{
    string inOrder = "", postOrder = "";

    In(root, inOrder);
    Pre(root, postOrder);

    node *t = buildTree(postOrder, inOrder, 0, inOrder.length() - 1);
    return t;
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
    cout << endl;

    node *t = MirrorImage(root);
    InOrder(t);
}
