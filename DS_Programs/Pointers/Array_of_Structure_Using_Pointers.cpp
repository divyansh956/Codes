#include <stdio.h>
#include <malloc.h>
struct Student
{
    int RollNo;
    char Name[50];
    double perc;
};

void Input(struct Student *ptr, int N)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d%s%lf", &((ptr + i)->RollNo), (ptr + i)->Name, &((ptr + i)->perc));
    }
}

void OutPut(struct Student *ptr, int N)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        printf("Student Details %d".i + 1);
        printf("%d %s %lf", (ptr + i)->RollNo, (ptr + i)->Name, (ptr + i)->perc);
        printf("\n");
    }
}

int main()
{
    int N;
    struct Student *p;
    printf("How many Students do you want to Input: ");
    scanf("%d", &N);

    p = (struct Student *)malloc(N * sizeof(struct Student));

    Input(p, N);
    OutPut(p, N);
}
