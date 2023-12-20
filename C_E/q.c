#include <stdio.h>
#include <stdlib.h>
int func1(int *var)
{
    return *var + 1;;
}
int main()
{
    int iPtr;
    iPtr = 1;
    printf("%d\n", iPtr);
    printf("%d\n", func1(&iPtr));
    printf("%d\n", iPtr);
    system("pause");
    return 0;
}