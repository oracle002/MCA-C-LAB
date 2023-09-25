# include <stdio.h>

#define MAX 25




struct employee
{
	int empno;
	char name[MAX];
	float esal;
	int dno;
};

struct employee reademp()
{
	struct employee e;
	printf("\nENTER EMPNO:\t ");
	scanf("%d",&e.empno);
	printf("\nENTER NAME:\t ");
	gets(e.name);
	gets(e.name);
	printf("\nENTER Department No:\t ");
	scanf("%d",&e.dno);
	printf("\nENTER Salarey:\t ");
	scanf("%f",&e.esal);
	return e;
}
printemp(struct employee e)
{

    printf("\nEMPLOYEE NO: %d",e.empno);
	printf("\nEMPLOYEE NAME: %s",e.name);
	printf("\nDEPARTEMENT NO: %d",e.dno);
	printf("\nSALAREY: %f",e.esal);
	printf("\n");
}
searchemp(struct employee e[],int n)
{
    int i,flag=0;
    int z;
    printf("Enter the empno:");
    scanf("%d",&z);
    for(i=0;i<n;i++)
    {
        if(e[i].empno==z)
        {
            flag=1;
            printemp(e[i]);
            break;
        }
    }
    if(flag==0)
    {
        printf("Not found");
    }

}
sortemp(struct employee e[],int n)
{
    int i, j;
    struct employee temp;
    int swapped;

    if (n > 0)
    {
        for (i = 0; i < n - 1; i++)
        {
            swapped = 0; // Initialize swapped flag for this pass
            for (j = 0; j < n - i - 1; j++)
            {
                if (e[j].empno > e[j + 1].empno)
                {
                    // Swap the elements
                    temp = e[j];
                    e[j] = e[j + 1];
                    e[j + 1] = temp;
                    swapped = 1; // Set swapped flag to true
                }
            }

            // If no two elements were swapped in the inner loop, the array is already sorted
            if (swapped == 0)
                break;
        }
    }
    else
    {
        printf("empty array");
    }
}

int main()
{
	struct employee a[MAX];
	int n,i;
	printf("ENTER NO OF RECORDS TO ENTER:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
    {
        a[i]=reademp();
    }
    printf("\n=====EMPLOYEE DETAILS=====\n");
    for(i=0;i<n;i++)
    {
        printemp(a[i]);
    }
    searchemp(a,n);
    sortemp(a,n);

	return 0;
}
