#include <stdio.h>

#define MAX_SIZE 10

void printMatrix(float matrix[MAX_SIZE][MAX_SIZE+1], int size) 
{
	int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j <= size; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(float matrix[MAX_SIZE][MAX_SIZE+1], int size) 
{
	int i, j, k;
    for (i = 0; i < size; i++) {
        // Pivot element
        float pivot = matrix[i][i];

        // Divide the pivot row by the pivot element
        for (j = i; j <= size; j++) {
            matrix[i][j] /= pivot;
        }

        // Elimination
        for (j = 0; j < size; j++) {
            if (j != i) {
                float factor = matrix[j][i];
                for (k = i; k <= size; k++) {
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }
    }
}

int main() 
{
    int i, j, size;

    printf("Enter the number of equations: ");
    scanf("%d", &size);

    float matrix[MAX_SIZE][MAX_SIZE+1];

    printf("Enter the augmented matrix coefficients:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j <= size; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("\nAugmented Matrix:\n");
    printMatrix(matrix, size);

    // Apply Gauss-Jordan method
    gaussJordan(matrix, size);

    printf("Solution:\n");
    for (i = 0; i < size; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][size]);
    }

    return 0;
}
