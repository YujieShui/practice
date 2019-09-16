
静态变量、静态方法和 this 指针的使用。

```c++
/* 面向对象，静态变量、静态方法, this 指针 */

#include <iostream>
#include <cstring>

class Student
{
private:
    // 学生编号
    int number;
    // 学生分数
    int score;

public:
    // 静态变量，学生总数
    static int studentCount;
    // 静态变量，所有学生总分
    static int sumScore;

public:

    Student(int number, int score)
    {
        this->number = number;
        this->score = score;

        studentCount++;
        sumScore += score;
    }

    // 静态方法
    static double getAvg()
    {
        return sumScore / studentCount;
    }

    Student(/* args */);
};

// 静态变量赋值，所有对象共享
int Student::sumScore = 0;
int Student::studentCount = 0;

int main()
{
    Student stu1(111, 50);
    Student stu2(112, 70);
    Student stu3(114, 90);

    // 静态方法调用
    double avg = Student::getAvg();

    std::cout << "average score = " << avg << std::endl;

    return 0;    
}
```


静态成员变量：

1. static 成员变量实现了同类对象间信息共享。
2. static 成员类外存储,求类大小,并不包含在内。
3. static 成员是命名空间属于类的全局变量,存储在 data 区
4. static 成员只能类外初始化。
5. 可以通过类名访问(无对象生成时亦可),也可以通过对象访问

静态成员函数：

1. 静态成员函数的意义,不在于信息共享,数据沟通,而在于管理静态数据成员, 完成对静态数据成员的封装。
2. 静态成员函数只能访问静态数据成员。原因:非静态成员函数,在调用时 this 指针被当作参数传进。而静态成员函数属于类,而不属于对象,没有 this 指针

this 指针:

1. 类成员变量的形参和类的属性名字相同，可以使用 this 指针，如 `this->name = name`
