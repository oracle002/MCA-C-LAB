# include <stdio.h>

int main()
{
    int a[10],count=0,n;
    int i,c;
    printf("enter number of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter number to count");
    scanf("%d",&c);
    for(i=0;i<n;i++)
    {
        if(a[i]==c)
        {
            count++;
        }
    }
    printf("enter number of instance of %d in array is %d",c,count);
    return 0;
}