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

int addPoly(int coeff1[], int expo1[], int t1, int coeff2[], int expo2[], int t2, int coeff3[], int expo3[]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (expo1[i] == expo2[j]) {
            coeff3[k] = coeff1[i] + coeff2[j];
            expo3[k] = expo1[i];
            i++;
            j++;
            k++;
        } else if (expo1[i] > expo2[j]) {
            coeff3[k] = coeff1[i];
            expo3[k] = expo1[i];
            i++;
            k++;
        } else {
            coeff3[k] = coeff2[j];
            expo3[k] = expo2[j];
            j++;
            k++;
        }
    }

    while (i < t1) {
        coeff3[k] = coeff1[i];
        expo3[k] = expo1[i];
        i++;
        k++;
    }

    while (j < t2) {
        coeff3[k] = coeff2[j];
        expo3[k] = expo2[j];
        j++;
        k++;
    }

    return k;
}

void displayPoly(int coeff[], int expo[], int term) {
    int k;

    for (k = 0; k < term - 1; k++)
        printf("%d(x^%d) + ", coeff[k], expo[k]);
    printf("%d(x^%d)", coeff[term - 1], expo[term - 1]);
}

int main() {
    int t1, t2, t3;
    int coeff1[10], expo1[10], coeff2[10], expo2[10], coeff3[20], expo3[20];

    printf("Enter the first polynomial:\n");
    t1 = readPoly(coeff1, expo1);

    printf("\nFirst polynomial: ");
    displayPoly(coeff1, expo1, t1);

    printf("\n\nEnter the second polynomial:\n");
    t2 = readPoly(coeff2, expo2);

    printf("\nSecond polynomial: ");
    displayPoly(coeff2, expo2, t2);

    t3 = addPoly(coeff1, expo1, t1, coeff2, expo2, t2, coeff3, expo3);

    printf("\n\nResultant polynomial after addition: ");
    displayPoly(coeff3, expo3, t3);

    printf("\n");

    return 0;
}
