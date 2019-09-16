/* 按行读写 */
#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fp = fopen("../data/file02.txt", "r+");

    if(fp == NULL)
    {
        perror("fopen(): file is NULL.");
    }

    char tmp[100] = "aaaaaaaaa";
    fputs(tmp, fp);

    char buf[100];
    while(!feof(fp))
    {
        char *p = fgets(buf, sizeof(buf), fp);
        if(p != NULL)
        {
            printf("buf = %s", buf);
            printf("p = %s", p);
        }
    }

    return 0;
}