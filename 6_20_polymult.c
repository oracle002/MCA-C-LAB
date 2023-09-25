# include <stdio.h>

struct poly
{
    int coeff;
    int exp;
};

int main()
{
    struct poly p1[10],p2[10],p3[10];
    int t1,t2,i,j,k;
    printf("-----------INPUT CONSOLE-------------\n");
    printf("Enter the degree of P1");
    scanf("%d",&t1);
    for(i=0;i<t1;i++)
    {
        printf("Enter x[%d]^x:",i+1);
        scanf("%d^%d",&p1[i].coeff,&p1[i].exp);
    }
    printf("Enter the degree of P2");
    scanf("%d",&t2);
    for(i=0;i<t2;i++)
    {
        printf("Enter x[%d]^x:",i+1);
        scanf("%d^%d",&p2[i].coeff,&p2[i].exp);
    }
    printf("\n----------------------------------");
    k=0;
     for(i=0;i<t1;i++)
    {
        for(j=0;j<t2;j++)
        {
            p3[k].coeff=p1[i].coeff*p2[j].coeff;
            p3[k].exp=p1[i].exp+p2[j].exp;
            k++;
        }
    }
    printf("======POLYNOMIAL MULTIPLICATION=====");

    for(i=0;i<t1;i++)
    {
        printf("%dx^%d",p3[i].coeff,p3[i].exp);
        if(k >= i)
        {
            printf(" +");
        }
    }


    return 0;
}
