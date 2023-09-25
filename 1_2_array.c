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

void del()
{
    int z, i;
    if (n > 0)
    {
        printf("Enter the index to delete\n");
        scanf("%d", &z);
        if (z < n && z >= 0)
        {
            printf("\n%d is deleted from index %d", a[z], z);
            for (i = z; i < n - 1; i++)
            {
                a[i] = a[i + 1];
            }
            n--; // Decrease the size of the array after deletion
        }
    }
    else
    {
        printf("empty array");
    }
}

void search()
{
    int z, i;
    if (n > 0)
    {
        printf("Enter the number to search\n");
        scanf("%d", &z);
        for (i = 0; i < n; i++)
        {
            if (a[i] == z)
            {
                printf("\n%d at index position %d", a[i], i);
                break;
            }
        }
        if (i == n)
        {
            printf("\n%d not found in the array", z);
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
            swapped = 0; // Initialize swapped flag for this pass
            for (j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    // Swap the elements
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
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

int menu() // menu function
{
    int ch;
    printf("\n=======MENU========\nINSERT-1\nSEARCH-2\nDISPLAY-3\nSORT-4\nDELETE-5\nEXIT-6\nEnter A Choice:");
    scanf("%d", &ch);
    return ch;
}

void process()
{
    int ch;
    for (ch = menu(); ch != 6; ch = menu())
    {
        switch (ch)
        {
        case 1:
            insertion();
            break;
        case 2:
            search();
            break;
        case 3:
            disp();
            break;
        case 4:
            sort();
            break;
        case 5:
            del();
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
