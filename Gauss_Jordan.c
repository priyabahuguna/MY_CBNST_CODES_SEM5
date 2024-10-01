#include <stdio.h>
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
    printf("Name: Priya Bahuguna\nRoll No: 44\nSection: C\n\t\t\tGauss Jordan Method\n");
    // Step 1: Enter matrix order
    printf("Enter the matrix order (n): \n");
    scanf("%d", &n);

    float matrix[10][10]; // Augmented matrix of size n x (n+1)

    // Step 2: Enter the augmented matrix
    printf("Enter the augmented matrix (n x n+1):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Step 3: Perform Gauss-Jordan Elimination to transform matrix into diagonal form
    for (int i = 0; i < n; i++)
    {
        // Make the diagonal element 1 (by dividing the entire row)
        float diagElement = matrix[i][i];
        for (int j = 0; j <= n; j++)
        {
            matrix[i][j] = matrix[i][j] / diagElement;
        }

        // Make all elements in the column except the diagonal element 0
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                float factor = matrix[k][i];
                for (int j = 0; j <= n; j++)
                {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
        if (i < n - 1)
        {
            printf("After step %d, Intermediate Matrix:\n", i + 1);
            printMatrix(matrix, n);
        }
        else
        {
            printf("Upper Triangular Matrix\n", i + 1);
            printMatrix(matrix, n);
        }
    }

    // Step 4: Display the final results (solutions)
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }

    return 0;
}
