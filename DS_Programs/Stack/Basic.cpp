#include <stdio.h>
#define STACKSIZE 10
#define true 1
#define false 0

struct stack
{
    int item[STACKSIZE];
    int top;
};
struct stack s;

void Initialize()
{
    s.top = -1;
}

int isEmpty()
{
    if (s.top == -1)
    {
        return 1;
    }
    return 0;
}

void push(int x)
{
    if (s.top == STACKSIZE - 1)
    {
        printf("Stack Overflow");
    }
    s.top++;
    s.item[s.top] = x;
}

int pop()
{
    int x;
    if (isEmpty())
    {
        printf("Stack Underflows");
    }
    x = s.item[s.top];
    s.top--;
    return x;
}

int top()
{
    if (isEmpty())
    {
        printf("Stack Is Empty");
    }
    return s.item[s.top];
}

int main()
{
    int x;
    Initialize();
    push(100);
    push(200);
    push(300);
    push(400);
    pop();
    x = top();
    printf("%d", x);
}
