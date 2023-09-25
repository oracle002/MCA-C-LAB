#include <stdio.h>

int a[10], n;

void insertion()
{
    int i;
    printf("Enter no of elements (up to 10):\n");
    scanf("%d", &n);

    if (n <= 10) {
        printf("Enter elements:\n");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
    } else {
        printf("Array size exceeded. Maximum allowed size is 10.\n");
    }
}

void disp()
{
    int i;
    if (n > 0)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d\t", a[i]);
        }
    }
    else
    {
        printf("empty array");
    }
}


void sort()
{
    int i, j;
    int temp;
    int swapped;

    if (n > 0)
    {
        for (i = 0; i < n - 1; i++)
        {
            swapped = 0; 
            for (j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                 
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    swapped = 1; 
                }
            }

            if (swapped == 0)
                break;
        }
    }
    else
    {
        printf("empty array");
    }
}

int menu() // menu function
{
    int ch;
    printf("\n=======MENU========\nINSERT-1\nDISPLAY-2\nSORT-3\nnEXIT-4\nEnter A Choice:");
    scanf("%d", &ch);
    return ch;
}

void process()
{
    int ch;
    for (ch = menu(); ch != 4; ch = menu())
    {
        switch (ch)
        {
        case 1:
            insertion();
            break;
        case 2:
            disp();
            break;
        case 3:
            sort();
            break;

        default:
            printf("Invalid Choice\n");
        }
    }
}

int main()
{
    process();
    return 0;
}
