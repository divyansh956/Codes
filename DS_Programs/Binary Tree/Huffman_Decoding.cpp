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

void HuffmanCoding(node *root, string ss, unordered_map<char, string> &codes)
{
    if (root->data != '\0')
    {
        codes[root->data] = ss;
        return;
    }

    HuffmanCoding(root->left, ss + "0", codes);
    HuffmanCoding(root->right, ss + "1", codes);
}

string decryption(string encode, unordered_map<char, string> &codes)
{
    string ans;

    unordered_map<string, char> decode;
    for (auto x : codes)
    {
        decode[x.second] = x.first;
    }

    string temp = "";
    for (int i = 0; i < encode.length(); i++)
    {
        temp += encode[i];

        if (decode.find(temp) != decode.end())
        {
            ans += decode[temp];
            temp = "";
        }
    }

    return ans;
}

string encryption(string ss, unordered_map<char, string> &codes)
{
    unordered_map<char, int> mp;

    for (int i = 0; i < ss.length(); i++)
    {
        mp[ss[i]]++;
    }

    int n = mp.size();

    char sym[n];
    int freq[n];

    int i = 0;
    for (auto x : mp)
    {
        sym[i] = x.first;
        freq[i] = x.second;
        i++;
    }

    node *root = HuffmanTree(sym, freq, n);

    HuffmanCoding(root, "", codes);

    for (auto x : codes)
    {
        cout << x.first << " : " << x.second;
        cout << endl;
    }

    string encode;
    for (int i = 0; i < ss.length(); i++)
    {
        encode += codes[ss[i]];
    }

    return encode;
}

int main()
{
    string ss;
    cin >> ss;

    unordered_map<char, string> codes;

    string encode = encryption(ss, codes);
    cout << "Encrypted: " << encode << endl;

    string ans = decryption(encode, codes);
    cout << "Decrypted: " << ans << endl;
}
