#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float diffPercent = 1;

    for (int studentNumber = 1; studentNumber < 24; studentNumber++)
    {
        printf("studentNumber :%d, diffPercent :%f \n", studentNumber, diffPercent * (1 - ((studentNumber - 1) / 365.0f)));
    }

    system("pause");
    return 0;
}