#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double func(double x)
{
    return cos(x) + 1 - 3 * x;
}
double q1(double x)
{
    return (cos(x) + 1) / 3;
}

double q2(double x)
{
    return acos(3 * x - 1);
}

double q1_derivative(double x)
{
    return -sin(x) / 3;
}

double q2_derivative(double x)
{
    return -3 / sqrt(1 - pow(3 * x - 1, 2));
}

double choose_q(double x)
{
    double dq1 = q1_derivative(x);
    double dq2 = q2_derivative(x);

    // Return the q(x) whose derivative is closer to 0
    return fabs(dq1) < fabs(dq2) ? q1(x) : q2(x);
}

void iteration(double x0, double tolerance, int max_iteration)
{
    double x1;
    int iteration_count = 0;

    printf("\nIteration\t\tx0\t\tf(x0)\n");

    do
    {
        x1 = choose_q(x0); // Calculate x1 using the q(x) with the derivative closest to 0
        printf("%d\t\t\t%.6lf\t\t%.6lf\n", iteration_count, x0, func(x0));

        if (fabs(x1 - x0) <= tolerance)
        {
            // If the change in x (error) is within tolerance, print the root and exit
            printf("Root found: x = %.6lf\n", x1);
            return;
        }

        x0 = x1;
        iteration_count++;
    } while (iteration_count < max_iteration);

    printf("Root not found within the maximum number of iterations.\n");
}

int main()
{
    double x0, x1, tolerance;
    int max_iteration = 100;
    printf("Name: Priya Bahuguna\nRoll No: 44\nSection: C\n\t\t\tIteration Method\n");
    printf("\nEnter first guess = ");
    scanf("%lf", &x0);
    printf("\nEnter second guess = ");
    scanf("%lf", &x1);
    printf("\nEnter the tolerance = ");
    scanf("%lf", &tolerance);

    // Choose the initial guess closest to 0
    if (fabs(x1) < fabs(x0))
    {
        double temp = x0;
        x0 = x1;
        x1 = temp;
        printf("\nGuess Chosen = ", x0);
    }
    iteration(x0, tolerance, max_iteration);
    return 0;
}
