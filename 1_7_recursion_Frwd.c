#include <stdio.h>
void disp(int a[],int i)
{
    if(i<=4)
    {
        printf("%d",a[i]);
        i++;
        disp(a,i);    
    }
        
}

int main()
{
    int a[5]={1,5,9,3,5};
    disp(a,0);
    return 0;
}