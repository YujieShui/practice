/* 结构体深拷贝、浅拷贝 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char *name;
    int age;
} Student;

int main()
{
    Student stu;
    stu.name = (char *)malloc(30);
    strcpy(stu.name, "aaaaaa");

    // 浅拷贝，stu 和 sut2 的name 指针指向同一块内存
    Student stu2;
    stu2 = stu;
    printf("name = %s\n", stu2.name);

    // 深拷贝，stu3 重新申请一块内存
    Student stu3;
    stu3.name = (char *)malloc(30);
    strcpy(stu3.name, stu.name);
    printf("name = %s\n", stu3.name);

    if(stu.name != NULL)
    {
        free(stu.name);
        stu.name = NULL;
    }

/*  
    // 浅拷贝，重复释放会报错
    if(stu2.name != NULL)
    {
        free(stu2.name);
        stu2.name = NULL;
    }
*/
    if(stu3.name != NULL)
    {
        free(stu3.name);
        stu3.name = NULL;
    }

    return 0;
}