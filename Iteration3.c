#include <stdio.h>
#include <math.h>

double func(double x)
{
    return x * x * x + x * x - 1;
}

double q1(double x)
{
    return pow((1 - x * x), 1.0 / 3);
}

double q2(double x)
{
    return pow((1 - x * x), 1.0 / 2);
}

double q3(double x)
{
    return pow((1 + x), -1.0 / 2);
}

double deri_q1(double x)
{
    return (-2 * x) / (3 * pow((1 - x * x), 2.0 / 3));
}

double deri_q2(double x)
{
    return (-2 * x) / (2 * pow((1 - x * x), 1.0 / 2));
}

double deri_q3(double x)
{
    return 1 / (2 * pow((1 + x), 3.0 / 2));
}

double choose(double x)
{
    double dq1 = fabs(deri_q1(x));
    double dq2 = fabs(deri_q2(x));
    double dq3 = fabs(deri_q3(x));

    if (dq1 < dq2 && dq1 < dq3)
    {
        return q1(x);
    }
    else if (dq2 < dq3)
    {
        return q2(x);
    }
    else
    {
        return q3(x);
    }
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
