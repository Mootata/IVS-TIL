#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int main()
{
    int num1 = 20;
    int num2 = 30;
    int max_result = MAX(num1, num2);
    int min_result = MIN(num1, num2);
    printf("숫자 1: %d\n", num1);
    printf("숫자 2: %d\n", num2);
    printf("최댓값: %d\n", max_result);
    printf("최솟값: %d\n", min_result);
    return 0;
}
