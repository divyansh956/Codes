#include <bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string s;
    cin >> s;

    cout << prefixEvaluation(s) << endl;
}


/********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define stacksize 20
#define true 1
#define false 0
struct stack
{
    int item[stacksize];
    int top;
};
struct stack s;
void Initialize()
{
    s.top = -1;
}
void push(int x)
{
    if (s.top == (stacksize - 1))
    {
        printf("Stack overflows");
        return;
    }
    s.top = s.top + 1;
    s.item[s.top] = x;
}
int pop()
{
    int x;
    if (s.top == -1)
    {
        printf("Stack underflows");
        return 0;
    }
    x = s.item[s.top];
    s.top = s.top - 1;
    return x;
}
int IsEmpty()
{
    if (s.top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int evaluate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return b - a;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return b / a;
        break;
    case '^':
        return pow(a, b);
        break;
    }
}
int i = 0;
void infix(char str[20])
{
    while (str[i] != '\0')
    {
        while (str[i] >= '0' && str[i] <= '9')
        {
            push(str[i] - '0');
            i++;
        }
        int a = pop();
        int b = pop();
        int value = evaluate(a, b, str[i]);
        push(value);
        i++;
    }
    int x = pop();
    printf("%d", x);
}

int main()
{
    char str[13];
    gets(str);
    Initialize();
    infix(str);
}
