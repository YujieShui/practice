#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME  "../data/file03.txt"


struct teacher
{
	int age;
	int id;
	char *name;  
	int name_len;
};

int main(void)
{
	FILE *fp = NULL;
#if 0
	int write_ret = 0;

	fp = fopen(FILE_NAME, "wb+");
	if (fp == NULL) {
		fprintf(stderr, "fopen error\n");
		return -1;
	}


	struct  teacher t1;
	char *name = "zhang3";

	t1.age = 10;
	t1.id = 20;
	t1.name = malloc(64);
	memset(t1.name, 0, 64);
	strcpy(t1.name, name);
	t1.name_len = strlen(name);

	write_ret = fwrite(&t1, sizeof(struct teacher), 1, fp);
	if (write_ret < 0) {
		fprintf(stderr, "write error\n");
		return -1;
	}
	write_ret = fwrite(t1.name, t1.name_len, 1, fp);
	if (write_ret < 0) {
		fprintf(stderr, "write error\n");
		return -1;
	}

	if (fp != NULL) {
		fclose(fp);
	}

#endif


// #if 0
	struct teacher t2 = { 0 };
	int read_ret = 0;

	fp = fopen(FILE_NAME, "rb+");
	if (fp == NULL) {
		fprintf(stderr, "fopen r+error\n");
		return -1;
	}

	read_ret = fread(&t2, sizeof(struct teacher), 1, fp);
	if (read_ret < 0) {
		fprintf(stderr, "fread error\n");
		fclose(fp);
		return -1;
	}

	t2.name = malloc(t2.name_len + 1);
	memset(t2.name, 0, t2.name_len + 1);

	read_ret = fread(t2.name, t2.name_len, 1, fp);
	if (read_ret < 0) {
		fprintf(stderr, "fread error\n");
		fclose(fp);
		return -1;
	}

	printf("id : %d, age : %d, name:%s, name_len :%d\n", t2.id, t2.age, t2.name, t2.name_len);


	if (fp != NULL)
	{
		fclose(fp);
	}

// #endif

	return 0;
}