#include<stdio.h>

// malloc, free
#include<stdlib.h>

// strcpy
#include<string.h>

// fcntl - manipulate file descriptor
// open()
#include<fcntl.h>

// close, read, write, lseek
#include<unistd.h>

// off_t
#include<sys/types.h>

int main() {
// 申请20字节内存
	char* helloString = malloc(20*sizeof(char));
// 字符串常量
	char* src = "hello, glibc.\n";
// 将src指向的内存拷贝至helloString
	strcpy(helloString, src);

// 打开文件hello.txt, 没有责创建｜可读可写｜有则从零开始, rw_rw_r
	int fd_hello = open("hello.txt", O_CREAT | O_RDWR | O_TRUNC, 0664);
// 向文件fd_hello 写入helloString
	write(fd_hello, helloString, 20*sizeof(char));
// 关闭文件
	close(fd_hello);
// 清理申请的内存
	free(helloString);
	
	char* byeString = malloc(20*sizeof(char));
// 只读
	int fd_bye = open("bye.txt", O_RDONLY);
	read(fd_bye, byeString, 20*sizeof(char));
	printf("bye.txt: %s", byeString);
	close(fd_bye);
	free(byeString);

	char glibc2clang[5] = "clang";
	fd_bye = open("bye.txt", O_WRONLY);
// 在fd_bye原有的位置+5offset
	lseek(fd_bye, 5, SEEK_SET);
	write(fd_bye, glibc2clang, 5*sizeof(char));	
	close(fd_bye);

	return 0;
}
