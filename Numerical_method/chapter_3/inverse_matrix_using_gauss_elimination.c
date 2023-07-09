#include <stdio.h>

#define N 3

void printMatrix(float matrix[N][2 * N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 2 * N; j++)
            printf("%0.2f ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

void gaussElimination(float matrix[N][2 * N])
{
    int i, j, k;
    float factor;

    for (i = 0; i < N; i++)
    {
        // Divide the current row by matrix[i][i]
        factor = matrix[i][i];
        for (j = 0; j < 2 * N; j++)
            matrix[i][j] /= factor;

        // Eliminate other rows
        for (j = 0; j < N; j++)
        {
            if (j != i)
            {
                factor = matrix[j][i];
                for (k = 0; k < 2 * N; k++)
                    matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

int main()
{
    float matrix[N][2 * N] = {
        {1, -2, -1, 1, 0, 0},
        {1, -1, 2, 0, 1, 0},
        {2, -3, -1, 0, 0, 1}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix);

    gaussElimination(matrix);

    printf("Inverse Matrix:\n");
    printMatrix(matrix);

    return 0;
}
