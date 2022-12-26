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


/**********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
    struct node *next;
};

struct node *MakeNode(char x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->next = NULL;
    
    return p;
}

int prcd(char a, char b)
{
    if (a == '^' || a == '*' || a == '/' || a == '%')
    {
        if (b == '^')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (a == '+' || a == '-')
        {
            if (b == '+' || b == '-')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

struct node *BuildExpTree(char *Exp)
{
    int i = 0;
    char symb, op;

    struct node *x, *y;
    struct node *START = NULL, *p, *q;

    char opStk[20];
    int top = -1;

    while (Exp[i] != '\0')
    {
        symb = Exp[i];
        i++;

        if (symb >= 'a' && symb <= 'z' || symb >= 'A' && symb <= 'Z' || symb >= '0' && symb <= '9')
        {
            x = MakeNode(symb);
            x->next = START;
            START = x;
        }
        else
        {
            while (top != -1 && prcd(opStk[top], symb))
            {
                op = opStk[top--];
                y = MakeNode(op);

                p = START;
                START = START->next;

                q = START;
                START = START->next;

                y->right = p;
                y->left = q;

                y->next = START;
                START = y;
            }
            opStk[++top] = symb;
        }
    }

    while (top != -1)
    {
        op = opStk[top--];
        y = MakeNode(op);

        p = START;
        START = START->next;

        q = START;
        START = START->next;

        y->right = p;
        y->left = q;

        y->next = START;
        START = y;
    }

    return START;
}

void PreOrderTraversal(struct node *T)
{
    if (T != NULL)
    {
        printf("%c", T->data);
        PreOrderTraversal(T->left);
        PreOrderTraversal(T->right);
    }
}

void InOrderTraversal(struct node *T)
{
    if (T != NULL)
    {
        InOrderTraversal(T->left);
        printf("%c", T->data);
        InOrderTraversal(T->right);
    }
}

void PostOrderTraversal(struct node *T)
{
    if (T != NULL)
    {
        PostOrderTraversal(T->left);
        PostOrderTraversal(T->right);
        printf("%c", T->data);
    }
}

int main()
{
    char Expression[20];
    scanf("%s", Expression);

    struct node *T = BuildExpTree(Expression);

    PreOrderTraversal(T);
    printf("\n\n");
    InOrderTraversal(T);
    printf("\n\n");
    PostOrderTraversal(T);
}
