#include <stdio.h>

#define MAX_DEGREE 100

void readPolynomial(int polynomial[MAX_DEGREE]) {
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    for (int i = 0; i <= degree; i++) {
        printf("Enter the coefficient for degree %d: ", i);
        scanf("%d", &polynomial[i]);
    }
}

void displayPolynomial(int polynomial[MAX_DEGREE]) {
    int degree = polynomial[0]; 
    printf("Polynomial: ");
    for (int i = degree; i >= 0; i--) {
        if (i == degree) {
            printf("%dx^%d", polynomial[i], i);
        } else {
            printf(" + %dx^%d", polynomial[i], i);
        }
    }
    printf("\n");
}

void addPolynomials(int result[MAX_DEGREE], int poly1[MAX_DEGREE], int poly2[MAX_DEGREE]) {
    int degree1 = poly1[0];
    int degree2 = poly2[0];
    int degree = (degree1 > degree2) ? degree1 : degree2;

    for (int i = 0; i <= degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }

    result[0] = degree; 
}

int main() {
    int polynomial1[MAX_DEGREE] = {0}; 
    int polynomial2[MAX_DEGREE] = {0};
    int result[MAX_DEGREE] = {0};

    printf("Enter Polynomial 1:\n");
    readPolynomial(polynomial1);

    printf("Enter Polynomial 2:\n");
    readPolynomial(polynomial2);

    printf("\nPolynomial 1:\n");
    displayPolynomial(polynomial1);

    printf("\nPolynomial 2:\n");
    displayPolynomial(polynomial2);

    addPolynomials(result, polynomial1, polynomial2);

    printf("\nResultant Polynomial after Addition:\n");
    displayPolynomial(result);

    return 0;
}
