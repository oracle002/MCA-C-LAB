# include <stdio.h>
# include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(int e)
{
    node *t;
    if(head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        head->data=e;
        head->next=NULL;
    }
    else
    {
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=(node*)malloc(sizeof(node));
        t->next->data=e;
        t->next->next=NULL;
    }
}
void disp()
{
    node *t;
    if(head==NULL)
    {
        printf("\nEMPTY LINKED LIST");
    }
    else
    {
      t=head;
      while(t!=NULL)
      {
          printf("%d\t",t->data);
          t=t->next;

      }
    }
}
void appendb(int e)
{
    node *t=(node*)malloc(sizeof(node));
    if(head==NULL)
    {
        printf("EMPTY");
    }
    else
    {
        t->data=e;
        t->next=head;
        head=t;
    }
}
/*void append(int e)
{
        int ch;
        printf("APPED TO BEGINNING-1\nAPPEND TO MIDDLE-2\nAPPEND TO END-3");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:appendb();
        }


}*/
int main()
{
    int a,i=0,z;
    printf("ENTER THE NUMBER OF ELEMENTS YOU WANT TO ENTER:\n");
    scanf("%d",&a);
    do{
        printf("ENTER ElEMENT:\n");
        scanf("%d",&z);
        insert(z);
        i++;
    }while(i!=a);
    printf("%d\n",a);
    disp();
    appendb(10);
    printf("\n");
    disp();
    return 0;
}
