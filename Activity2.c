# include <stdio.h>
# include <malloc.h>


typedef struct node{
    int data;
    struct node* next;
}node;
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

int sum(node *t)
{

    int a,b,c;
    if(t==NULL)
    {
        printf("\n EMPTY LINKED LIST");
    }
    else
    {
      while(t!=NULL)
      {
        a=t->data;
        b=t->next->data;
        c=a+b;
      }
    }
    return c;
}

int reduce()
{
    node *t;
    if(head==NULL)
    {
        printf("\n EMPTY LINKED LIST");
    }
    else
    {
      t=head;
      printf("\n");
      while(t!=NULL)
      {
        t->data=sum(t);
        t=t->next;
      }

    }
}

    /*node *z;
    node *t;
    t=head;

    while(t!=NULL)
    {
    if(zhead==NULL)
    {
        zhead=(node*)malloc(sizeof(node));
        zhead->data=t->data+t->next->data;
        zhead->next=NULL;
    }
    else
    {
        z=zhead;
        while(z!=NULL)
        {
            z=z->next;
        }
        z->next=(node*)malloc(sizeof(node));
        z->next->data=t->data+t->next->data;
        z->next->next=NULL;
      }
      t=t->next;

    }*/



/*void dispii()
{

    node *z;
    if(zhead==NULL)
    {
        printf("\n EMPTY LINKED LIST");
    }
    else
    {
      z=zhead;
      printf("\n Z LINKED LIST\n");
      while(z!=NULL)
      {
          printf("%d\t",z->data);
          z=z->next;

      }
    }
}*/




int main()
{
    insert(10);
    insert(11);
    insert(12);
    insert(13);
    disp();
    reduce();
    printf("\n");
    disp();
    return 0;

}
