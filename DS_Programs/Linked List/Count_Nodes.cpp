#include <stdio.h>
#include <stdlib.h>

struct node
{
     int info;
     struct node *next;
};

struct node *start;
int cnt = 0;
int even = 0, odd = 0;

struct node *GetNode()
{

     struct node *p;
     p = start;
     p = (struct node *)malloc(sizeof(struct node *));
     return p;
}

void InsEnd(int x)
{
     struct node *q = start;
     while (q->next != NULL)
     {
          q = q->next;
     }
     struct node *p = GetNode();
     p->info = x;
     p->next = NULL;
     q->next = p;
}

void InsBeg(int x)
{
     struct node *p;
     p = GetNode();
     p->info = x;
     p->next = start;
     start = p;
}

void traverse()
{
     struct node *p;
     p = start;
     while (p != NULL)
     {
          if (p->info % 2 == 0)
          {
               even++;
          }
          else
          {
               odd++;
          }

          cnt++;
          printf("%d ", p->info);
          p = p->next;
     }
}


int main()
{
     start = NULL;
     InsBeg(100);
     InsBeg(23);
     InsBeg(300);
     InsBeg(500);
     InsBeg(97);
     InsBeg(300);
     InsEnd(1000);
     InsEnd(39);

     printf("Linked List: ");
     traverse();
     printf("\nNodes: %d", cnt);
     printf("\nEven: %d", even);
     printf("\nOdd: %d", odd);
}
