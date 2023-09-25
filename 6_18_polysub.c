#include <stdio.h>

struct poly
{
    int coeff;
    int exp;
};

int main()
{
    struct poly p1[10], p2[10], p3[10];
    int t1, t2, i, j, k;
    printf("Enter the Number of elements in P1: ");
    scanf("%d", &t1);
    for (i = 0; i < t1; i++)
    {
        printf("Enter the coefficient and exponent for %d term of P1: ", i + 1);
        scanf("%d^%d", &p1[i].coeff, &p1[i].exp);
    }
    printf("Enter the Number of elements in P2: ");
    scanf("%d", &t2);
    for (i = 0; i < t2; i++)
    {
        printf("Enter the coefficient and exponent for %d term of P2: ", i + 1);
        scanf("%d^%d", &p2[i].coeff, &p2[i].exp);
    }

    i = 0;
    j = 0;
    k = 0;

    while (i < t1 && j < t2)
    {
        if (p1[i].exp == p2[j].exp)
        {
            p3[k].coeff = p1[i].coeff - p2[j].coeff; // Subtract coefficients
            p3[k].exp = p1[i].exp;
            k++;
            i++;
            j++;
        }
        else if (p1[i].exp > p2[j].exp)
        {
            p3[k].coeff = p1[i].coeff;
            p3[k].exp = p1[i].exp;
            k++;
            i++;
        }
        else
        {
            p3[k].coeff = -p2[j].coeff; // Negate the coefficient for subtraction
            p3[k].exp = p2[j].exp;
            k++;
            j++;
        }
    }
    while (i < t1)
    {
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        k++;
        i++;
    }
    while (j < t2)
    {
        p3[k].coeff = -p2[j].coeff; 
        p3[k].exp = p2[j].exp;
        k++;
        j++;
    }

    printf("======POLYNOMIAL SUBTRACTION=====\n");

    for (i = 0; i < k; i++)
    {
        printf("%dx^%d", p3[i].coeff, p3[i].exp);
        if (p3[i].exp >= 1)
        {
            printf(" + ");
        }
    }

    printf("\n");

    return 0;
}
