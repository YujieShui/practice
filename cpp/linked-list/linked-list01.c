#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    int age; // 数据域
    char name[50];
    struct Student *next; // 指针域
}Student;

typedef struct Student student_t;

int main()
{
    student_t stu1 = {11, "Mike"};
    student_t stu2 = {13, "John"};
    student_t stu3 = {12, "Lucy"};

    stu1.next = &stu2;
    stu2.next = &stu3;

    student_t *p = &stu1;

    while(p != NULL)
    {
        printf("age = %d, name = %s\n", p->age, p->name);
        p = p->next;
    }

    return 0;
}