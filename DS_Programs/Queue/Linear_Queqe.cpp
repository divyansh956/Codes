#include <stdio.h>
#define QUEUQSIZE 100
#define true 1
#define false 0

struct Queue
{
   int item[QUEUQSIZE];
   int rear;
   int front;
};
struct Queue q;

void Initialize()
{
   q.rear = -1;
}

int isEmpty()
{
   if (q.rear - q.front == -1)
   {
      return 1;
   }
   return 0;
}

void push(int x)
{
   if (q.rear == QUEUQSIZE - 1)
   {
      printf("Queue Overflow");
      return;
   }
   q.rear++;
   q.item[q.rear] = x;
}

int pop()
{
   int x;
   if (isEmpty())
   {
      printf("Queue Underflows");
      return -1;
   }
   x = q.item[q.front];
   q.front++;
   return x;
}

int front()
{
   if (isEmpty())
   {
      printf("Queue Is Empty");
      return -1;
   }
   return q.item[q.front];
}

int main()
{
   int x;
   Initialize();
   push(200);
   push(100);
   push(300);
   push(400);
   pop();
   pop();
   x = front();
   printf("%d", x);
}
