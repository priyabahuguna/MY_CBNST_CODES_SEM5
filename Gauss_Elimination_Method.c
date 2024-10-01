#include <stdio.h>
#include <math.h>

void printMatrix(float matrix[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Name: Priya Bahuguna\nRoll No: 44\nSection: C\n\t\t\tGauss Elimination Method\n");
    printf("Enter the matrix order (n): \n");
    scanf("%d", &n);

    float matrix[10][10]; // augmented matrix of size n x (n+1)

    // Step 2: Input Augmented Matrix
    printf("Enter the augmented matrix (n x n+1):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Step 3: Forward Elimination (Transform to Upper Triangular Matrix)
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] == 0)
        {
            printf("Mathematical Error! Zero pivot encountered at row %d.\n", i + 1);
            return -1;
        }

        for (int j = i + 1; j < n; j++)
        {
            float ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= n; k++)
            {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
        if (i < n - 1)
        {
            printf("\nAfter step %d, Intermediate Matrix:\n", i + 1);
            printMatrix(matrix, n);
        }
        else
        {
            printf("\nUpper Triangular Matrix\n", i + 1);
            printMatrix(matrix, n);
        }
    }

    // Step 4: Back Substitution
    float solution[10];
    for (int i = n - 1; i >= 0; i--)
    {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++)
        {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    printf("\nFinal values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }

    return 0;
}
