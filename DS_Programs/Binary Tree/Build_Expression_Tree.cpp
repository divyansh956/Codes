#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    node *left;
    node *right;

    node(char val)
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

void PreOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
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

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/' || c == '%')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

node *buildExpressionTree(string s)
{
    stack<node *> operand;
    stack<char> symbol;

    for (int i = 0; i < s.length(); i++)
    {
        char sym = s[i];

        if (sym >= 'a' && sym <= 'z')
        {
            node *x = new node(sym);
            operand.push(x);
        }
        else
        {
            while (!symbol.empty() && prec(symbol.top()) >= prec(sym))
            {
                if (symbol.top() == '^' && s[i] == '^')
                {
                    break;
                }

                char op = symbol.top();
                symbol.pop();

                node *t = new node(op);

                node *b = operand.top();
                operand.pop();

                node *a = operand.top();
                operand.pop();

                t->left = a;
                t->right = b;

                operand.push(t);
            }
            symbol.push(sym);
        }
    }

    while (!symbol.empty())
    {
        char op = symbol.top();
        symbol.pop();

        node *t = new node(op);

        node *b = operand.top();
        operand.pop();

        node *a = operand.top();
        operand.pop();

        t->left = a;
        t->right = b;
        
        operand.push(t);
    }

    return operand.top();
}

int main()
{
    string s;
    cin >> s;

    node *root = buildExpressionTree(s);
    InOrder(root);
    cout << endl;
    PreOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
}
