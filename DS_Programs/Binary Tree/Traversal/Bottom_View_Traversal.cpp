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

void solve(node *root, int hd, map<int, vector<int>> &mp)
{
    if (root == NULL)
    {
        return;
    }

    mp[hd].push_back(root->data);

    solve(root->left, hd - 1, mp);
    solve(root->right, hd + 1, mp);
}

void bottomView(node *root)
{
    map<int, vector<int>> mp;
    int hd = 0;

    solve(root, hd, mp);

    for (auto x : mp)
    {
        cout << x.second[x.second.size() - 1] << " ";
    }
    cout << endl;
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

    bottomView(root);
}
