#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float input, average = 0;

    for (int i = 1; i < 6; i++)
    {
        scanf("%f", &input);
        average = ((average * (i - 1)) + input) / i;
        printf("average : %f \n", average);
    }

    system("pause");
    return 0;
}