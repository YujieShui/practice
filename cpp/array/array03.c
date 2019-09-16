
#include <stdio.h>

int main()
{

    printf("========== 指针数组 ==========\n");

    // 数组指针： 是数组，每个元素都是指针
    // [] 优先级高于 *
    char *c[] = {"aaaaaaaa", "bbbbbbbb", "cccccccc", "dddddddd"};

    int length_b = sizeof(c) / sizeof(c[0]);

    for (int i = 0; i < length_b; i++)
    {
        printf("%s ", c[i]);
    }
    printf("\n");

    printf("========== 数组指针 ==========\n");

    int b[10] = {0};

    // () 和 [] 优先级相同
    // () 中有指针，它是一个指针
    int(*point)[10];
    point = &b;

    for (int i = 0; i < 10; ++i)
    {
        (*point)[i] = 2 * i + 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", (*point)[i]);
    }
    printf("\n");

    return 0;
}