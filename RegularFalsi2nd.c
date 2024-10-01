#include <stdio.h>
#include <math.h>
double createFunc(double x)
{
    return cos(x) - x * exp(x);
}
double regular_falsi(double x0, double x1, double tolerance)
{
    double x2;
    int iteration = 0;

    if (createFunc(x0) * createFunc(x1) >= 0)
    {
        printf("The Regular Falsi method cannot be applied. Invalid guesses.\n");
        return -1;
    }
    printf("Itr\t x0\t\t\t x1\t\t\t x2\t\t\t f(x2)\n");
    do
    {
        x2 = x0 - (createFunc(x0) * (x1 - x0)) / (createFunc(x1) - createFunc(x0));
        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n", iteration, x0, x1, x2, createFunc(x2));

        if (createFunc(x2) == 0.0)
        {
            break;
        }
        else if (createFunc(x0) * createFunc(x2) < 0)
        {
            x1 = x2;
        }
        else
        {
            x0 = x2;
        }
        iteration++;
    } while (fabs(createFunc(x2)) > tolerance && iteration < 100);

    printf("The final approximate root is at x = %.6f\n", x2);
    printf("Number of iterations: %d\n", iteration);
    return x2;
}

int main()
{
    printf("Name: Priya Bahuguna \nRoll No: 44 \nSection: C\n\t\t\t\t****REGULAR FALSI METHOD****\n\n");
    double x0, x1, tolerance;
    printf("Enter two guesses : \n");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter tolerance :\n ");
    scanf("%lf", &tolerance);
    regular_falsi(x0, x1, tolerance);
    return 0;
}