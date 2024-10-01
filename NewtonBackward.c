#include <stdio.h>
#include <stdbool.h> // Include this header for using bool type

int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// Function to calculate the backward difference table
void calculateBackwardDifference(float diffTable[10][10], int n)
{
    for (int j = 1; j < n; j++)
    {
        for (int i = n - 1; i >= j; i--)
        {
            diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
        }
    }
}

// Function to print the backward difference table
void printBackwardDifferenceTable(float x[10], float diffTable[10][10], int n)
{
    printf("\nBackward Difference Table:\n");
    printf("   x      f(x)   ");
    for (int j = 1; j < n; j++)
    { // Print the right number of difference columns
        printf("∇^%d f(x)   ", j);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%.2f   %.2f   ", x[i], diffTable[i][0]);
        for (int j = 1; j <= i; j++)
        { // Corrected the range of j for proper difference printing
            printf("%.2f   ", diffTable[i][j]);
        }
        printf("\n");
    }
}

// Main function implementing Newton's Backward Interpolation Method
int main()
{
    int n;

    // Input number of data points
    printf("Name: Priya Bahuguna\nRoll No: 44\nSection: C\n\t\t\tNewton Backward Interpolation Method\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[10];     // Years
    float y[10][10]; // Population for corresponding years

    // Input data points for x and f(x)
    printf("Enter the data points (year and population):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
        scanf("%f", &y[i][0]);
    }

    // Check if the interval h is the same
    float h = x[1] - x[0];    // Calculate the first interval
    bool sameInterval = true; // Flag to check interval consistency

    for (int i = 2; i < n; i++)
    {
        if (x[i] - x[i - 1] != h)
        { // Check if the current interval matches the first interval
            sameInterval = false;
            break;
        }
    }

    // If intervals are not the same, display an error message and exit
    if (!sameInterval)
    {
        printf("Error: The intervals between years are not the same.\n");
        return 1; // Exit with an error code
    }

    // Value of x to calculate
    float value;
    printf("\nCalculating population for the year: ");
    scanf("%f", &value);

    // Construct the backward difference table
    calculateBackwardDifference(y, n);

    // Print the backward difference table
    printBackwardDifferenceTable(x, y, n);

    // Applying Newton Backward Interpolation Formula
    float result = y[n - 1][0];                   // Initial value f(xn)
    float u = (value - x[n - 1]) / (x[1] - x[0]); // Calculate u
    float uTerm = 1;                              // u term for multiplication
    for (int i = 1; i < n; i++)
    {
        uTerm *= (u + (i - 1));                         // Calculate u(u+1)(u+2).../(i!)
        result += (uTerm * y[n - 1][i]) / factorial(i); // Add next term to result
    }

    // Output the result
    printf("Result:\nYear: %.0f\tPopulation: %.2f\n", value, result);

    return 0;
}
