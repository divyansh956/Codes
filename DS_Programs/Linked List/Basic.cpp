#include <stdio.h>
#include <stdlib.h>

struct node
{
     int info;
     struct node *next;
};

struct node *start;

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
          printf("%d->", p->info);
          p = p->next;
     }
}

int main()
{
     start = NULL;
     InsBeg(100);
     InsBeg(200);
     InsBeg(300);
     InsBeg(500);
     InsBeg(100);
     InsBeg(300);
     InsEnd(1000);
     InsEnd(600);
     traverse();
}
