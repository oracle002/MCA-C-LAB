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
        printf("\n EMPTY LINKED LIST");
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
        printf("\n EMPTY");
    }
    else
    {
        t->data=e;
        t->next=head;
        head=t;
    }
}
int appendm(int e)
{
    int z;
    node *t=(node*)malloc(sizeof(node));
    node *a;
    if(head==NULL)
    {
        printf("\n EMPTY");
    }
    else
    {
        a=head;
        int flag=0;
        printf("\n ENTER THE NUMBER TO APPEND AFTER:");
        scanf("%d",&z);
        while(a!=NULL)
        {
          if(a->data==z)
          {
              flag=1;
              break;
          }
          a=a->next;

        }
        if(flag==0)
        {
            printf("\n NUMBER IS NOT IN LIST");
            return e;

        }
        t->data=e;
        t->next=a->next;
        a->next=t;

        return e;

    }

}
enum amenu{BEGINNING=1,MIDDLE,END};

int append()
{
        int ch;
        printf("\n====APPEND MENU====");
        printf("\n APPED TO BEGINNING-1\n APPEND TO MIDDLE-2\n APPEND TO END-3 \n BACK TO MAIN MENU-4\n ENTER YOUR CHOICE:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case BEGINNING:printf("\n ENTER THE ELEMENT TO APPEND:");
                            scanf("%d",&ch);
                            appendb(ch);
                            break;
            case MIDDLE:printf("\n ENTER THE ELEMENT TO APPEND:");
                            scanf("%d",&ch);
                            appendm(ch);
                            break;
            case END:printf("\n ENTER THE ELEMENT TO APPEND:");
                            scanf("%d",&ch);
                            insert(ch);
                            break;
            deafult:
                mmenu();

        }
        return ch;


}
enum mmenu{INSERT=1,DISPLAY,APPEND,EXIT};
int mmenu()
{
    int ch;;
    printf("\n======MAIN MENU=======");
    printf("\n INSERT-1 \n DISPLAY-2\n APPEND-3\n EXIT-4 \n ENTER YOUR CHOICE:\n");
    scanf("%d",&ch);
    return ch;

}
void process()
{
    int ch;
    for(ch=mmenu();ch!=4;ch=mmenu())
    {
        switch(ch)
        {
            case INSERT:printf("\n ENTER THE ELEMENT TO INSERT:");
                            scanf("%d",&ch);
                            insert(ch);
                            break;
            case DISPLAY:printf("\n LINKED LIST:\n");
                        disp();
                        break;
            case APPEND:append();
                        break;
            deafult:
                printf("\ninvalid Choice");

        }
    }
}
int main()
{
    process();
    return 0;
}
