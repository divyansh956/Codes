#include <stdio.h>
#define cQUEUQSIZE 5
#define true 1
#define false 0

struct CQueue
{
   int item[cQUEUQSIZE];
   int rear;
   int front;
};
struct CQueue cq;

void Initialize()
{
   cq.rear = 0;
   cq.front = 0;
}

int isEmpty()
{
   if (cq.rear - cq.front == 0)
   {
      return 1;
   }
   return 0;
}

void push(int x)
{
   if ((cq.rear + 1) % cQUEUQSIZE == cq.front)
   {
      printf("Queue Overflows");
      return;
   }
   cq.rear = (cq.rear + 1) % cQUEUQSIZE;
   cq.item[cq.rear] = x;
}

int pop()
{
   int x;
   if (isEmpty())
   {
      printf("Queue Underflows ");
      return -1;
   }
   cq.front = (cq.front + 1) % cQUEUQSIZE;
   x = cq.item[cq.front];
   return x;
}

int front()
{
   if (isEmpty())
   {
      printf("Queue Is Empty ");
      return -1;
   }
   return cq.item[(cq.front + 1) % cQUEUQSIZE];
}

int main()
{
   int x;
   Initialize();
   push(300);
   push(500);
   push(100);
   pop();
   pop();
   pop();

   printf("%d", front());
}
