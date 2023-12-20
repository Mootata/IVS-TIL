#include <stdio.h>
// 제곱 함수
double square(double x)
{
    return x * x;
}
// 세제곱 함수
double cube(double x)
{
    return x * x * x;
}
// 네제곱 함수
double fourthPower(double x)
{
    return x * x * x * x;
}

int main()
{
    double (*functionPointers[])(double) = {square, cube, fourthPower};
    double num = 0;

    do{
        printf("실수를 입력하세요 (0을 입력하면 종료): ");
        scanf("%lf", &num);
        for (int i = 0; i < sizeof(functionPointers); i++){
            printf("함수 %d 결과: %f\n", i, functionPointers[i](num));
        }
    } while(num != 0);

    printf("프로그램을 종료합니다.\n");
    return 0;
}