#include <stdio.h>
#include <math.h>

double func(double x)
{
    return 2 * x - log10(x) - 7;
}

double q1(double x)
{
    return (7 + log10(x)) / 2;
}

double q2(double x)
{
    return pow(10, 2 * x - 7);
}
double deri_q1(double x)
{
    return 0.21715 / x;
}

double deri_q2(double x)
{
    return 2 * pow(10, 2 * x - 7) * log(10);
}

double choose(double x)
{
    double dq1 = fabs(deri_q1(x));
    double dq2 = fabs(deri_q2(x));
    return fabs(dq1) < fabs(dq2) ? q1(x) : q2(x);
}

void iterationMethod(double a, double tolerance)
{
    double b;
    int iteration = 0;
    printf("\nItr\t\tx0\t\tf(x0)\n");

    do
    {
        b = choose(a);
        printf("%d\t\t%.6f\t%.6f\n", iteration, a, func(a));
        if (fabs(func(b)) <= tolerance)
        {
            printf("\nRoot found at x = %.6f\n", b);
            return;
        }
        a = b;
        iteration++;
    } while (iteration < 100);
    printf("\nRoot not found within 100 iterations\n");
}

int main()
{
    double a, b, tolerance;
    printf("Enter first guess: ");
    scanf("%lf", &a);
    printf("Enter second guess:");
    scanf("%lf", &b);
    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);
    // guess chosen
    a = (a + b) / 2;
    printf("Guess Close to 0 should be chosen : %lf", a);
    iterationMethod(a, tolerance);
    return 0;
}
