#include <stdio.h>
int add(int a, int b)
{
    return a + b;
}
// subtract 함수 선언
int subtract(int a, int b)
{
    return a - b;
}

// multiply 함수 선언
int multiply(int a, int b)
{
    return a * b;
}

// divide 함수 선언
int divide(int a, int b)
{
    return a / b;
}

int main(int a, int b)
{
    // 함수 포인터 선언
    int (*operation)(int, int);
    int num1, num2;
    char operator;
    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &num1, &num2);
    printf("연산자를 선택하세요 (+, -, *, /): ");
    scanf(" %c", &operator);
    switch (operator)
    {
    case '+':
        = add(a, b);
    case '-':
        int(*operation) = subtract(a, b);

    case '*':
        int(*operation) = multiply(a, b);

    case '/':
        int(*operation) = divide(a, b);
    }
    int result = operation(num1, num2);
    printf("결과: %d\n", result);
    return 0;
}