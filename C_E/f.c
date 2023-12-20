#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double integral(double A, double B, double D, double N)
{
    double sum = 0;
    double deltaX = (B - A) / N;
    for (int k = 1; k <= N; k++)
    {
        sum += pow(A + k * deltaX, D);
    }
    return sum * deltaX;
}

int main()
{
    printf("%lf\n", integral(0, 2, 2, 1000));
    printf("%lf\n", integral(0, 2, 3, 1000));
    system("pause");
    return 0;
}