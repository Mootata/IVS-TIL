#include <stdio.h>

typedef struct
{
    char name;
    int id;
    int math_score;
    int english_score;
} Student;

void printStudentInfo(Student student1){
    printf("first student: \nName: %c\nID: %d\nMath Score: %d\nEnglish Score: %d\nAverage Score: %lf", student1->name)
}
