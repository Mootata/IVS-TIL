#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
unsigned int binaryToDecimal(unsigned int numOfDigit, unsigned int no)
{
    for (int i = 0; i < numOfDigit; i++)
    {
        no = no * 2;
    }
    return no;
}

int main()
{
    unsigned int num = 0;
    unsigned int arr[8] = {
        0,
    };
    unsigned int index = 0;
    unsigned int decimal = 0;
    system("chcp 65001");
    printf("부호가 없는(unsigned) 이진수를 0자리부터 8개 입력하세요 \n");
    while (index < 8)
    {
        scanf("%d", &num);
        arr[index] = num;
        index++;
    }
    for (int i = 0; i < 8; i++)
    {
        decimal += binaryToDecimal(i, arr[i]);
    }
    printf("2진법 수 : ");
    for (int i = sizeof(arr) - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    printf("10 진법 수 : %d\n", decimal);
    system("pause");
    return 0;
}