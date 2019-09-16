/* 面向对象，静态变量、静态方法, this 关键字 */

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