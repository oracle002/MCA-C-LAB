#include <stdio.h>
#include <conio.h>

# define MAX 10
int front =-1;

int rear=-1;
int Q[MAX];

int enqueue(int e)
{
    if(rear==-1&& front==-1)
    {
        rear++;
        front++;
        Q[rear]=e;
    }
    if(front==0)
    {
        Q[rear]=e;
        rear++;
    }
    heapify(e);
}
int dequeue()
{
    if(rear==0 && front==0)
    {
        printf("\n%d DELETED\n",Q[rear]);
        rear--;
        front--;
    }
    else if(rear==-1&& front==-1)
    {
        printf("\n EMPTY QUEUE");
    }
    else
    {
        printf("\n%d DELETED\n",Q[rear]);
        rear--;
    }
}

int disp()
{
    int z=front;
    if(rear==-1&& front==-1)
    {
        printf("\n EMPTY QUEUE");
    }
    else{
    do
    {
        printf("%d\t",Q[z]);
        z++;
    }while(z!=rear);
    }

}

int heapify(int e)
{
    int temp;
    if(rear==0 && front==0)
    {
        printf("single element");
        return 0;
    }
    int i=rear;
    int largest = e;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(e>Q[l]&&e>Q[r])
    {
        temp=Q[l];
        Q[l]=e;
        Q[i]=temp;
    }

}

int main(){

enqueue(10);
enqueue(50);
disp();
return 0;
}
