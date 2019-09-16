# 文件基础知识

## C语言文件指针

C语言中我们使用一个指针变量指向一个文件，这个文件就是文件指针。这个文件指针就是 FILE 结构体，它被包含在头文件 "stdio.h" 中。

# 标准文件读写

## 打开文件 fopen()

```
#include <stdio.h>
FILE *fopen(const char *path, const char *mode);
```

文件的打开操作表示返回一个指向制定文件的 **FILE 结构体**。我们需要指定文件位置和操作方式，特别需要注意的是区分不同的文件操作方式将会产生的结果。

```
r      Open text file for reading.  The stream  is  positioned  at  the beginning of the file.

r+     Open  for  reading and writing.  The stream is positioned at the beginning of the file.

w      Truncate file to zero length or create text  file  for  writing. The stream is positioned at the beginning of the file.

w+     Open  for  reading  and writing.  The file is created if it does not exist, otherwise it is truncated.  The stream is  positioned at the beginning of the file.

a      Open  for  appending (writing at end of file).  The file is created if it does not exist.  The stream is positioned at the  end of the file.

a+     Open  for  reading  and appending (writing at end of file).  The file is created if it does not exist.  The initial file position for  reading  is  at  the  beginning  of the file, but output is always appended to the end of the file.
```

## 关闭文件 fclose()

```
#include <stdio.h>
int fclose(FILE *stream);
```

文件操作完成后,必须要用fclose()函数进行关闭,这是因为对打开的文件进行写入时,若文件缓冲区的空间未被写入的内容填满,这些内容不会写到打开的文件中去而丢失。只有对打开的文件进行关闭操作时,停留在文件缓冲区的内容才能写到该文件中去,从而使文件完整。再者一旦关闭了文件,该文件对应的FILE结构将被释放,从而使关闭的文件得到保护,因为这时对该文件的存取操作将不会进行。文件的关闭也意味着释放了该文件的缓冲区。

它表示该函数将关闭FILE指针对应的文件,并返回一个整数值。若成功地关闭了文件,则返回一个0值,否则返回一个非0值。

## 文件读取

- [fgetc() 和 fputc() 按字符读取文件](file01.c)
- [fgets() 按行读写文件](file02.c)
- [fwrite() 和 fread() 按块读写文件](file03.c)