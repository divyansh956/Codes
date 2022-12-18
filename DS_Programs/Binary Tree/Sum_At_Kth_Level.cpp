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

int sumAtK(node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    int level = 0;
    int sum = 0;

    while (!q.empty())
    {
        node *p = q.front();
        q.pop();

        if (p != NULL)
        {
            if (level == k)
            {
                sum += p->data;
            } 

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
            level++;
        }
    }
    return sum;
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

    int k;
    cin >> k;

    cout << sumAtK(root, k) << endl;
}
