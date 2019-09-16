/* 按字符读写 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_fgetc(FILE *fp);
void my_fputc(FILE *fp);

int main()
{

    FILE *fp = fopen("../data/file01.txt", "r+");

    my_fgetc(fp);
    // my_fputc(fp);

    return 0;
}

void my_fputc(FILE *fp)
{
    if(fp == NULL)
    {
        perror("fopen() fail.");
        return;
    }

    char text[] = "This is a text for test.";
    int length = strlen(text);

    for(int i = 0; i < length; i++)
    {
        fputc(text[i], fp);
    }

    if(fp != NULL)
    {
        free(fp);
        fp = NULL;
    }
}

void my_fgetc(FILE *fp)
{
    if(fp == NULL)
    {
        perror("fputc() fail.");
        return;
    }

    char ch;

    while( (ch = fgetc(fp)) != EOF )
    {
        printf("%c", ch);
    }
    printf("\n");

#if 0
    while(!feof(fp))
    {
        ch = fgetc(fp);
        printf("%c", ch);
    }
    printf("\n");
#endif

    if(fp != NULL)
    {
        free(fp);
        fp = NULL;
    }
}