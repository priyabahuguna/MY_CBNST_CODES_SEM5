#include <stdio.h>
#include <math.h>

double createFunc(double x)
{
    return x * x * x - 9 * x + 1;
}

double secant(double x0, double x1, int max_iteration, double tolerance)
{
    double x2;
    int itr = 0;
    double f0, f1, f2;

    f0 = createFunc(x0);
    f1 = createFunc(x1);

    if (f0 == f1)
    {
        printf("\nMathematical Error: Division by zero.\n");
        return -1;
    }
    printf("Itr\t x0\t\t\t x1\t\t\t x2\t\t\t f(x2)\n");
    while (itr < max_iteration)
    {
        f0 = createFunc(x0);
        f1 = createFunc(x1);

        if (fabs(f1 - f0) < tolerance)
        {
            printf("\nFunction values are too close, solution might not be reliable.\n");
            return -1;
        }

        x2 = ((x0 * createFunc(x1)) - (x1 * createFunc(x0))) / (createFunc(x1) - createFunc(x0));
        printf("\n%d\t %.6f \t %.6f \t %.6f \t %.6f\n", itr, x0, x1, x2, createFunc(x2));
        f2 = createFunc(x2);

        if (fabs(f2) <= tolerance)
        {
            printf("\nThe root is x = %.6f\n", x2);
            printf("Total Number of Iterations = %d\n", itr + 1);
            return x2;
        }

        x0 = x1;
        x1 = x2;
        itr++;
    }

    printf("\nMethod did not converge within the maximum number of iterations.\n");
    printf("\nLast approximation x = %.6f\n", x2);
    return x2;
}

int main()
{
    double x0, x1, tolerance;
    int max_iteration;

    printf("Name: Priya Bahuguna\nRoll No: 44\nSection: C\n\t\t\tSecant Method\n");
    printf("\nEnter first guess = ");
    scanf("%lf", &x0);
    printf("\nEnter second guess = ");
    scanf("%lf", &x1);
    printf("\nEnter max iteration = ");
    scanf("%d", &max_iteration);
    printf("\nEnter the tolerance =\n ");
    scanf("%lf", &tolerance);

    secant(x0, x1, max_iteration, tolerance);

    return 0;
}
