#include <stdio.h>

#define MAX_TERMS 100

// Structure to represent a term of the polynomial
struct Term {
    int coefficient;
    int exponent;
};

// Function to read a polynomial
void readPolynomial(struct Term poly[], int* n) {
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", n);

    printf("Enter the coefficients and exponents in descending order:\n");
    for (int i = 0; i < *n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly[i].coefficient, &poly[i].exponent);
    }
}

// Function to display a polynomial
void displayPolynomial(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
        } else {
            printf(" + %dx^%d", poly[i].coefficient, poly[i].exponent);
        }
    }
    printf("\n");
}

// Function to add two polynomials
void addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[], int* nResult) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (poly1[i].exponent == poly2[j].exponent) {
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            result[k].exponent = poly1[i].exponent;
            i++;
            j++;
        } else if (poly1[i].exponent > poly2[j].exponent) {
            result[k] = poly1[i];
            i++;
        } else {
            result[k] = poly2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        result[k] = poly1[i];
        i++;
        k++;
    }

    while (j < n2) {
        result[k] = poly2[j];
        j++;
        k++;
    }

    *nResult = k;
}

// Function to subtract two polynomials
void subtractPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[], int* nResult) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (poly1[i].exponent == poly2[j].exponent) {
            result[k].coefficient = poly1[i].coefficient - poly2[j].coefficient;
            result[k].exponent = poly1[i].exponent;
            i++;
            j++;
        } else if (poly1[i].exponent > poly2[j].exponent) {
            result[k] = poly1[i];
            i++;
        } else {
            result[k].coefficient = -poly2[j].coefficient;
            result[k].exponent = poly2[j].exponent;
            j++;
        }
        k++;
    }

    while (i < n1) {
        result[k] = poly1[i];
        i++;
        k++;
    }

    while (j < n2) {
        result[k].coefficient = -poly2[j].coefficient;
        result[k].exponent = poly2[j].exponent;
        j++;
        k++;
    }

    *nResult = k;
}

// Function to multiply two polynomials
void multiplyPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[], int* nResult) {
    *nResult = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            result[*nResult].coefficient = poly1[i].coefficient * poly2[j].coefficient;
            result[*nResult].exponent = poly1[i].exponent + poly2[j].exponent;
            (*nResult)++;
        }
    }
}

int main() {
    struct Term poly1[MAX_TERMS], poly2[MAX_TERMS], result[MAX_TERMS];
    int n1, n2, nResult;

    printf("Enter the first polynomial:\n");
    readPolynomial(poly1, &n1);

    printf("Enter the second polynomial:\n");
    readPolynomial(poly2, &n2);

    printf("\nFirst polynomial: ");
    displayPolynomial(poly1, n1);

    printf("Second polynomial: ");
    displayPolynomial(poly2, n2);

    // Add polynomials
    addPolynomials(poly1, n1, poly2, n2, result, &nResult);
    printf("\nResult of addition: ");
    displayPolynomial(result, nResult);

    // Subtract polynomials
    subtractPolynomials(poly1, n1, poly2, n2, result, &nResult);
    printf("\nResult of subtraction: ");
    displayPolynomial(result, nResult);

    // Multiply polynomials
    multiplyPolynomials(poly1, n1, poly2, n2, result, &nResult);
    printf("\nResult of multiplication: ");
    displayPolynomial(result, nResult);

    return 0;
}
