#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *address;
};

int main()
{
    struct node *f,*t;
    int ch;
    f=(struct node*)malloc(sizeof(struct node));
    t=f;
    do
    {
        printf("\nENTER THE ELEMENTs\n");
        scanf("%d",t->address);
        printf("\nWANT TO ADD MORE(0/1)");
        scanf("%d",&ch);
        if(ch==1)
        {
            t->address=(struct node*)malloc(sizeof(struct node));
            t=t->address;
        }
        else
        {
            t->address=NULL;
        }
    }while(ch!=0);
    t=f;
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->address;
    }
    return 0;
}
