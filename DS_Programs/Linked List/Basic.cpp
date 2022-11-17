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

void InsAft(struct node **q, int x)
{
     struct node *p, *r;
     p = GetNode();
     p->info = x;
     r = (*q)->next;
     p->next = r;
     (*q)->next = p;
}

void InsEnd(struct node **start, int x)
{
     struct node *q = *start;
     while (q->next != NULL)
     {
          q = q->next;
     }
     struct node *p = GetNode();
     p->info = x;
     p->next = NULL;
     q->next = p;
}

void InsBeg(struct node **start, int x)
{
     struct node *p;
     p = GetNode();
     p->info = x;
     p->next = *start;
     *start = p;
}

void traverse(struct node *start)
{
     struct node *p;
     p = start;
     while (p != NULL)
     {
          printf("%d ", p->info);
          p = p->next;
     }
}

int main()
{
     struct node *start = NULL;
     InsBeg(&start, 100);
     InsBeg(&start, 23);
     InsBeg(&start, 300);
     InsBeg(&start, 500);
     InsBeg(&start, 97);
     InsBeg(&start, 300);
     InsEnd(&start, 1000);

     struct node *p = start;
     printf("Enter Positon to be Inserted: ");

     int idx;
     scanf("%d", &idx);

     for (int i = 1; i < idx; i++)
     {
          p = p->next;
     }

     InsEnd(&start, 39);
     InsAft(&p, 40);

     printf("Linked List: ");
     traverse(start);
}
