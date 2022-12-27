#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    int freq;
    node *next;
    node *left;
    node *right;

    node()
    {
        data = '\0';
        freq = 0;
        next = NULL;
        left = NULL;
        right = NULL;
    }
};

void PQInsert(node *&root, node *x)
{
    node *p = root;
    node *q = NULL;

    while (p != NULL && p->freq <= x->freq)
    {
        q = p;
        p = p->next;
    }

    if (q == NULL)
    {
        x->next = p;
        root = x;
        return;
    }

    x->next = q->next;
    q->next = x;
}

node *PQDelete(node *&root)
{
    node *p = root;
    root = root->next;

    return p;
}

node *HuffmanTree(char sym[], int freq[], int n)
{
    node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        node *x = new node();

        x->freq = freq[i];
        x->data = sym[i];

        PQInsert(root, x);
    }

    for (int i = 0; i < n - 1; i++)
    {
        node *x = PQDelete(root);
        node *y = PQDelete(root);

        node *z = new node();

        z->left = x;
        z->right = y;
        z->freq = x->freq + y->freq;

        PQInsert(root, z);
    }

    return PQDelete(root);
}

void HuffmanCoding(node *root, string ss, vector<pair<char, string>> &codes)
{
    if (root->data != '\0')
    {
        codes.push_back({root->data, ss});
        return;
    }

    HuffmanCoding(root->left, ss + "0", codes);
    HuffmanCoding(root->right, ss + "1", codes);
}

int main()
{
    int n;
    cin >> n;

    char sym[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sym[i];
    }

    int freq[n];
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];
    }

    node *root = HuffmanTree(sym, freq, n);

    vector<pair<char, string>> codes;
    HuffmanCoding(root, "", codes);

    for (auto x : codes)
    {
        cout << x.first << " : " << x.second;
        cout << endl;
    }
}
