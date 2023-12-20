#include <stdio.h>
// 조건부 컴파일을 위한 매크로 정의
#define FEATURE_A
int main()
{
// FEATURE_A 매크로가 정의되어 있는 경우에만 해당 코드 블록이 컴파일됩니다.
#ifdef FEATURE_A
    printf("이 코드는 FEATURE_A가 정의되어 있을 때만 컴파일됩니다.\n");
#else
    printf("이 코드는 FEATURE_A가 정의되어 있지 않을 때만 컴파일됩니다.\n");
#endif
// 다른 조건부 컴파일 예제
#ifndef FEATURE_B
    printf("이 코드는 FEATURE_B가 정의되어 있지 않을 때만 컴파일됩니다.\n");
#endif
// 두 개 이상의 조건을 조합하는 경우
#if defined(FEATURE_A) && !defined(FEATURE_C)
    printf("이 코드는 FEATURE_A가 정의되어 있고 FEATURE_C가 정의되어 있지 않을 때만 컴파일됩니다.\n");
#endif
    return 0;
}
