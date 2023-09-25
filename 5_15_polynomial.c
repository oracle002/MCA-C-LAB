#include <stdio.h>

int readPoly(int coeff[], int expo[]) {
    int t1, i;

    printf("\n\n Enter the total number of terms in the polynomial: ");
    scanf("%d", &t1);

    printf("\n Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < t1; i++) {
        printf("   Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &coeff[i]);
        printf("      Enter the exponent(%d): ", i + 1);
        scanf("%d", &expo[i]);
    }
    return t1;
}


   
void displayPoly(int coeff[], int expo[], int term) {
    int k;

    for (k = 0; k < term - 1; k++)
        printf("%d(x^%d) + ", coeff[k], expo[k]);
    printf("%d(x^%d)", coeff[term - 1], expo[term - 1]);
}

int main() {
    int t1, t2, t3;
    int coeff1[10], expo1[10];

    printf("Enter the  polynomial:\n");
    t1 = readPoly(coeff1, expo1);

    printf("\n polynomial: ");
    displayPoly(coeff1, expo1, t1);

    printf("\n");

    return 0;
}
