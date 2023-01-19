#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int height;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        height = 0;
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

            if (p->left != NULL)
            {
                q.push(p->left);
            }

            if (p->right != NULL)
            {
                q.push(p->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int rheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        else
        {
            int l = rheight(root->left);
            int r = rheight(root->right);
            return max(l, r) + 1;
        }
    }
}

int BalanceFactor(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int hl = 0, hr = 0;

    if (root->left == NULL)
    {
        hl = 0;
    }
    else
    {
        hl = 1 + root->left->height;
    }

    if (root->right == NULL)
    {
        hr = 0;
    }
    else
    {
        hr = 1 + root->right->height;
    }

    return (hl - hr);
}

node *LeftRotation(node *x)
{
    node *y = x->right;
    node *z = y->left;

    y->left = x;
    x->right = z;

    return y;
}

node *RightRotation(node *x)
{
    node *y = x->left;
    node *z = y->right;

    y->right = x;
    x->left = z;

    return y;
}

node *LL(node *x)
{
    node *y = RightRotation(x);
    return y;
}

node *RR(node *x)
{
    node *y = LeftRotation(x);
    return y;
}

node *LR(node *x)
{
    node *y = x->left;
    node *z = LeftRotation(y);

    x->left = z;
    node *t = RightRotation(x);

    return t;
}

node *RL(node *x)
{
    node *y = x->right;
    node *z = RightRotation(y);

    x->right = z;
    node *t = LeftRotation(x);

    return t;
}

node *deleteNode(node *&root, int val)
{
    node *prev = NULL;
    node *curr = root;

    while (curr != NULL && curr->data != val)
    {
        prev = curr;
        if (val < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    if (curr == NULL)
    {
        return root;
    }

    if (curr->left == NULL || curr->right == NULL)
    {
        node *newtree;

        if (curr->left == NULL)
        {
            newtree = curr->right;
        }
        else
        {
            newtree = curr->left;
        }

        if (prev == NULL)
        {
            return newtree;
        }

        if (curr == prev->left)
        {
            prev->left = newtree;
        }
        else
        {
            prev->right = newtree;
        }

        delete curr;
    }
    else
    {
        node *prev = NULL;
        node *t;

        t = curr->right;
        while (t->left != NULL)
        {
            prev = t;
            t = t->left;
        }

        if (prev != NULL)
        {
            prev->left = t->right;
        }
        else
        {
            curr->right = t->right;
        }
        curr->data = t->data;

        delete t;
    }

    return root;
}

node *AVLdelete(node *&root, int val)
{
    root = deleteNode(root, val);

    if (root == NULL)
    {
        return NULL;
    }

    root->height = rheight(root);

    if (BalanceFactor(root) == 2)
    {
        if (BalanceFactor(root->left) >= 0)
        {
            root = LL(root);
        }
        else
        {
            root = LR(root);
        }
    }
    else
    {
        if (BalanceFactor(root) == -2)
        {
            if (BalanceFactor(root->left) <= 0)
            {
                root = RR(root);
            }
            else
            {
                root = RL(root);
            }
        }
    }

    return root;
}

node *AVLinsert(node *&root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
        root->height = rheight(root);

        return root;
    }

    if (val < root->data)
    {
        root->left = AVLinsert(root->left, val);

        if (BalanceFactor(root) == 2)
        {
            if (val < root->left->data)
            {
                root = LL(root);
            }
            else
            {
                root = LR(root);
            }
        }
    }
    else
    {
        root->right = AVLinsert(root->right, val);

        if (BalanceFactor(root) == -2)
        {
            if (val >= root->right->data)
            {
                root = RR(root);
            }
            else
            {
                root = RL(root);
            }
        }
    }

    root->height = rheight(root);

    return root;
}

node *makeAVLtree(int nums[], int n)
{
    node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        AVLinsert(root, nums[i]);
    }

    return root;
}

int main()
{
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    node *root = makeAVLtree(nums, n);
    levelOrder(root);
    cout << endl;

    AVLdelete(root, 10);
    
    levelOrder(root);
    cout << endl;

    // preOrder(root);
    // cout << endl;
    // InOrder(root);
    // cout << endl;
    // PostOrder(root);
    // cout << endl;
}
