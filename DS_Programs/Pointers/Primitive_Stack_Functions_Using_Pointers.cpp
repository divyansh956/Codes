#include <stdlib.h>
#include <iostream>
#define stacksize 20
#define true 1
#define false 0

struct stack
{
    int item[stacksize];
    int top;
};

void Initialize(struct stack *st)
{
    st->top = -1;
}

int IsEmpty(struct stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Top(struct stack *st)
{
    if (st->top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        return st->item[st->top];
    }
}

void push(struct stack *st, int x)
{
    if (st->top == (stacksize - 1))
    {
        printf("Stack Overflows\n");
        return;
    }
    st->top++;
    st->item[st->top] = x;
}

int pop(struct stack *st)
{
    int x;
    if (st->top == -1)
    {
        printf("Stack Underflows");
        return 0;
    }
    x = st->item[st->top];
    st->top--;
    return x;
}

int main()
{
    int x;
    struct stack s;

    Initialize(&s);

    push(&s, 400);
    push(&s, 600);
    push(&s, 987);
    push(&s, 567);

    x = pop(&s);
    printf("Popped element: %d\n", x);

    x = Top(&s);
    printf("Top element: %d\n", x);

    x = pop(&s);
    printf("Popped element: %d\n", x);

    printf("%d\n", IsEmpty(&s));
}
