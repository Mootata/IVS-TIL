#include <stdio.h>
#include "student.h"

int main()
{
    // 첫 번째 학생 정보 생성
    Student student1 = {"Alice", 1, 90, 85};
    printf("First Student:\n");
    printStudentInfo(&student1);
// FEATURE_SECOND_STUDENT 매크로가 정의되어 있는 경우에만 두 번째 학생 정보 생성 및 출력
#ifdef FEATURE_SECOND_STUDENT
    Student student2 = {"Bob", 2, 78, 92};
    printf("\nSecond Student:\n");
    printSecondStudentInfo(&student2);
#endif
    return 0;
}
