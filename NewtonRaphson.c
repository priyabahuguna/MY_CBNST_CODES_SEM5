#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x)
{
    return cos(x) - x * (exp(x));
}
double derivative(double x)
{
    return -sin(x) - (x + 1) * (exp(x));
}

void newtonRaphson(double x0, double tolerance, int max_iter)
{
    printf("Iters\t x_prev\t\t x1_new\t\t x2\t\t \n");
    double x_new, x_prev = x0;
    int iter = 0;

    while (iter < max_iter)
    {

        x_new = x_prev - func(x_prev) / derivative(x_prev);
        printf("%d\t %.6f\t %.6f\t %.6f\n", iter, x_prev, x_new, func(x_new));
        // Check if the result is within the tolerance
        if (fabs(x_new - x_prev) < tolerance)
        {
            printf("approx root after %d iters is : %lf", iter, x_new);
            exit(0);
        }

        x_prev = x_new; // Update for next iteration
        iter++;
    }
    printf("wrong guesses\n");
}

int main()
{
    printf("Name: PRIYA BAHUGUNA \nRoll No: 44 \nSection: C\n\t\tNEWTON RAPHSON METHOD\n\n");
    double x0, a, b;  // Initial guesses
    double tolerance; // Tolerance level
    printf("Enter 2 guesses = \n");
    scanf("%lf%lf", &a, &b);
    printf("Enter tolerance = \n");
    scanf("%lf", &tolerance);
    if (func(a) * func(b) > 0)
    {
        printf("\nerror");
        exit(0);
    }
    if (a < b)
        x0 = a;
    else if (b < a)
        x0 = b;
    else
        x0 = (a + b) / 2.0;
    newtonRaphson(x0, tolerance, 50);

    return 0;
}
>>>>>>> e924bdf84357e9463d49cfe46bce916cc4218ba0
