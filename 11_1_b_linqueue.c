
#include <stdio.h>
#include <malloc.h>
struct node 
{
    int data;
    struct node *next;
};
typedef struct node queue;
enum op{ENQUEUE=1,DEQUEUE,EXIT};
queue *f=NULL,*r = NULL;
void enqueue(int e)
{
    queue *t = (queue *)malloc(sizeof(queue));
    t->data = e;
    t->next = NULL;
    if(f == NULL)
    {
        f = t;
        r = t;
    }
    else
    {
        r->next = t;
        r = t;
    }
}
void dequeue() 
{
    if(f == NULL)
        printf("\nEmpty QUEUE");
    else {
        printf("\n%d",f->data);
        f = f->next;
        if(f == NULL)
            r = NULL;
    }
}
int menu() {
    int ch;
    printf("\nENQUEUE - 1\nDEQUEUE - 2\nEXIT - 3\n Ur Choice : ");
    scanf("%d",&ch);
    return ch;
}
void processQueue()
{
    int ch;
    for(ch = menu();ch != 3;ch = menu()) 
    {
        switch(ch) 
        {
            case ENQUEUE:
                printf("Enter the element to enqueue");
                scanf("%d",&ch);
                enqueue(ch);
                break;
            case DEQUEUE:
                dequeue();
                break;
        }
    }
}
int main()
{
    processQueue();
    return 0;
}
