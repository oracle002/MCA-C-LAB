#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int matrix1[MAX_ROWS][MAX_COLS];
int matrix2[MAX_ROWS][MAX_COLS];
int result[MAX_ROWS][MAX_COLS];
int rows, cols;

void readMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}


void addMatrices() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}


void subMatrices() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void mulMatrices() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}


void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int choice;

    printf("Enter the number of rows and columns for the matrices (both should be <= 10): ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements for the first matrix:\n");
    readMatrix(matrix1, rows, cols);

    printf("Enter elements for the second matrix:\n");
    readMatrix(matrix2, rows, cols);

    do {
        printf("\n======= MENU =======\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose Matrix\n");
        printf("5. Display Result Matrix\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMatrices();
                printf("Result of Addition:\n");
                displayMatrix(result, rows, cols);
                break;
            case 2:
                subMatrices();
                printf("Result of Subtraction:\n");
                displayMatrix(result, rows, cols);
                break;
            case 3:
                mulMatrices();
                printf("Result of Multiplication:\n");
                displayMatrix(result, rows, cols);
                break;
            case 4:
                printf("Transpose of Matrix 1:\n");
                transposeMatrix(matrix1, rows, cols);
                displayMatrix(matrix1, cols, rows);
                break;
            case 5:
                printf("Result Matrix:\n");
                displayMatrix(result, rows, cols);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 6);

    return 0;
}
